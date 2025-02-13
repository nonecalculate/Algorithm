#include "SpartaCharacter.h"
#include "SpartaPlayerController.h"
#include "SpartaGameState.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Blueprint/UserWidget.h"
#include "Components/WidgetComponent.h"
#include "Components/TextBlock.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"

ASpartaCharacter::ASpartaCharacter():
	LowHealthWidgetClass(nullptr),
	LowHealthWidgetInstance(nullptr),
	DeathSound(nullptr),
	DeepBreathSound(nullptr),
	HurtSound(nullptr),
	ReliefSound(nullptr)
{
 	
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 300.0f;
	SpringArmComp->bUsePawnControlRotation = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Caamera"));
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
	CameraComp->bUsePawnControlRotation = false;

	OverheadWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("OverheadWidget"));
	OverheadWidget->SetupAttachment(GetMesh());
	OverheadWidget->SetWidgetSpace(EWidgetSpace::Screen);

	NormalSpeed = 600.0f;
	CurrentSpeed = NormalSpeed;
	SprintSpeedMultiplier = 1.7f;
	SprintSpeed = NormalSpeed * SprintSpeedMultiplier;
	MoveForwardInput = 0.0f;
	MoveRightInput = FVector2D::ZeroVector;
	LookRotation = FRotator::ZeroRotator;
	CameraRotation = FRotator::ZeroRotator;
	RotationSpeed = 1.0f;
	CurrentVelocity = FVector::ZeroVector;
	GetCharacterMovement()->bOrientRotationToMovement = false;
	GetCharacterMovement()->bUseControllerDesiredRotation = true;
	GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;

	MaxHealth = 100.0f;
	MinimumSpeed = 100.0f;
	Health = MaxHealth;
}


void ASpartaCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent)) 
	{
		if (ASpartaPlayerController* PlayerController = Cast<ASpartaPlayerController>(GetController()))
		{
			if (PlayerController->MoveForwardAction)
			{
				EnhancedInput->BindAction(
					PlayerController->MoveForwardAction,
					ETriggerEvent::Triggered,
					this,
					&ASpartaCharacter::HandleMoveForwardInput
				);
				EnhancedInput->BindAction(
					PlayerController->MoveForwardAction,
					ETriggerEvent::Completed,
					this,
					&ASpartaCharacter::HandleMoveForwardInput
				);
			}
			if (PlayerController->MoveRightAction)
			{
				EnhancedInput->BindAction(
					PlayerController->MoveRightAction,
					ETriggerEvent::Triggered,
					this,
					&ASpartaCharacter::HandleMoveRightInput
				);
				EnhancedInput->BindAction(
					PlayerController->MoveRightAction,
					ETriggerEvent::Completed,
					this,
					&ASpartaCharacter::HandleMoveRightInput
				);
			}
			if (PlayerController->JumpAction)
			{
				EnhancedInput->BindAction(
					PlayerController->JumpAction,
					ETriggerEvent::Triggered,
					this,
					&ASpartaCharacter::StartJump
				);
				EnhancedInput->BindAction(
					PlayerController->JumpAction,
					ETriggerEvent::Completed,
					this,
					&ASpartaCharacter::StartJump
				);
			}
			if (PlayerController->LookAction)
			{
				EnhancedInput->BindAction(
					PlayerController->LookAction,
					ETriggerEvent::Triggered,
					this,
					&ASpartaCharacter::Look
				);
			}
			if (PlayerController->SprintAction)
			{
				EnhancedInput->BindAction(
					PlayerController->SprintAction,
					ETriggerEvent::Triggered,
					this,
					&ASpartaCharacter::StartSprint
				);

				EnhancedInput->BindAction(
					PlayerController->SprintAction,
					ETriggerEvent::Completed,
					this,
					&ASpartaCharacter::StopSprint
				);
			}
		}
	}
}

void ASpartaCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Controller)
	{
		FVector CurrentLocation = GetActorLocation();
		FVector NextLocation = GetActorLocation();
		if (MoveForwardInput != 0.0f)
		{
			FVector ForwardVector = GetActorForwardVector() * MoveForwardInput * CurrentSpeed * DeltaTime;
			CurrentLocation += ForwardVector;
		}

		if (MoveRightInput != FVector2D::ZeroVector)
		{
			FVector RightVector = GetActorRightVector() * MoveRightInput.Y * CurrentSpeed * DeltaTime;
			CurrentLocation += RightVector;
		}

		SetActorLocation(CurrentLocation, true); // true 이게 있으면 앞에 벽이 있어 움직이지 못할 것 같다 싶으면 아예 움직이는 모션도 안나오게 한다
		CurrentVelocity = (CurrentLocation - NextLocation)/ DeltaTime;
	}
}

void ASpartaCharacter::HandleMoveForwardInput(const FInputActionValue& value)
{
	if (!Controller) return;
	MoveForwardInput = value.Get<float>();
}

void ASpartaCharacter::HandleMoveRightInput(const FInputActionValue& value)
{
	if (!Controller) return;
	MoveRightInput = value.Get<FVector2D>();
}

void ASpartaCharacter::StartJump(const FInputActionValue& value)
{
	if (value.Get<bool>())
	{
		Jump();
	}
}

void ASpartaCharacter::StopJump(const FInputActionValue& value)
{
	if (!value.Get<bool>())
	{
		StopJumping();
	}
}

void ASpartaCharacter::Look(const FInputActionValue& value)
{
	FVector2D LookInput = value.Get<FVector2D>();

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		float Yaw = LookInput.X * RotationSpeed;
		float Pitch = LookInput.Y * RotationSpeed;

		PlayerController->AddYawInput(Yaw);
		PlayerController->AddPitchInput(Pitch);

		FRotator CurrentRotation = SpringArmComp->GetRelativeRotation();
		//Clamp 로 pitch 값을 최소 / 최대 값으로 제한해줄 수 있다.
		float NewPitch = FMath::ClampAngle(CurrentRotation.Pitch + Pitch, -89.0f, 89.0f);
		SpringArmComp->SetRelativeRotation(FRotator(NewPitch, 0.0f, 0.0f));
	}
}

void ASpartaCharacter::StartSprint(const FInputActionValue& value)
{
	if (!Controller) return;
	CurrentSpeed = SprintSpeed;
}

void ASpartaCharacter::StopSprint(const FInputActionValue& value)
{
	if (!Controller) return;
	CurrentSpeed = NormalSpeed;
}

float ASpartaCharacter::GetHealth() const
{
	return Health;
}

void ASpartaCharacter::AddHealth(float Amount)
{
	Health = FMath::Clamp(Health + Amount, 0.0f, MaxHealth);
	UpdateOverheadHP();

	if (ReliefSound)
	{
		UGameplayStatics::PlaySoundAtLocation(
			GetWorld(),
			ReliefSound,
			GetActorLocation()
		);
	}

	if (Health > 40.0f && LowHealthWidgetInstance != nullptr)
	{
		LowHealthWidgetInstance->RemoveFromViewport();
		LowHealthWidgetInstance = nullptr;
	}
}

float ASpartaCharacter::TakeDamage(
	float DamageAmount,
	struct FDamageEvent const& DamageEvent,
	AController* EventInstigator,
	AActor* DamgeCauser )
{
	float ActualDamage = Super::TakeDamage(DamageAmount,
		DamageEvent,
		EventInstigator,
		DamgeCauser);

	Health = FMath::Clamp(Health - DamageAmount, 0.0f, MaxHealth);
	UpdateOverheadHP();
	if (Health > 40.0f)
	{
		if (HurtSound)
		{
			UGameplayStatics::PlaySoundAtLocation(
				GetWorld(),
				HurtSound,
				GetActorLocation()
			);
		}
	}
	if (Health <= 40.0f && LowHealthWidgetInstance == nullptr)
	{
		if (DeepBreathSound)
		{
			UGameplayStatics::PlaySoundAtLocation(
				GetWorld(),
				DeepBreathSound,
				GetActorLocation()
			);
		}
		if (HurtSound)
		{
			UGameplayStatics::PlaySoundAtLocation(
				GetWorld(),
				HurtSound,
				GetActorLocation()
			);
		}
		LowHealthWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), LowHealthWidgetClass);
		if (LowHealthWidgetInstance)
		{
			LowHealthWidgetInstance->AddToViewport();
		}
	}
	if (Health <= 0.0f)
	{
		if (DeathSound)
		{
			UGameplayStatics::PlaySoundAtLocation(
				GetWorld(),
				DeathSound,
				GetActorLocation()
			);
		}
		OnDeath();
	}

	return ActualDamage;
}

void ASpartaCharacter::OnDeath()
{
	
	ASpartaGameState* SpartaGameState = GetWorld() ? GetWorld()->GetGameState<ASpartaGameState>() : nullptr;
	if (SpartaGameState)
	{
		SpartaGameState->LevelDuration = 100.0f;
		DisableCollision();
		GetMesh()->SetCollisionProfileName(TEXT("Ragdoll"));
		GetMesh()->SetSimulatePhysics(true);
		SpartaGameState->OnGameOver();
	}
	
}

void ASpartaCharacter::DisableCollision()
{
	GetCharacterMovement()->DisableMovement();
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("NoCollision"));
}

void ASpartaCharacter::UpdateOverheadHP()
{
	if (!OverheadWidget)return;
	
	UUserWidget* OverheadWidgetInstance = OverheadWidget->GetUserWidgetObject();
	if (!OverheadWidgetInstance) return;

	if (UTextBlock* HPText = Cast<UTextBlock>(OverheadWidgetInstance->GetWidgetFromName(TEXT("OverHeadHP"))))
	{
		HPText->SetText(FText::FromString(FString::Printf(TEXT("%.0f / %.0f"), Health, MaxHealth)));
	}
}

/*
	
	개선점
	캐릭터 이동은 좀더 물리적으로 접근할 필요가 있다. 단순하게 W 를 눌렀으니
	초당 600정도의 속도를 내! 이런 방식보다는 물리적으로 속도를 정규화 하고
	현재 속도에 보간을 적용하여 부드러운 가감속을 구현해보도록 노력하자.
*/