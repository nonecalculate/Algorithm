#include "SpartaCharacter.h"
#include "SpartaPlayerController.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


ASpartaCharacter::ASpartaCharacter()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 300.0f;
	SpringArmComp->bUsePawnControlRotation = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Caamera"));
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
	CameraComp->bUsePawnControlRotation = false;


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

		SetActorLocation(CurrentLocation, true);
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