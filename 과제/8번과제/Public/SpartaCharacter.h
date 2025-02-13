#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpartaCharacter.generated.h"


class USpringArmComponent;
class UCameraComponent;
class UWidgetComponent;
class UUserWidget;
struct FInputActionValue;


UCLASS()
class SPARTAP_API ASpartaCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASpartaCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera")
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	UWidgetComponent* OverheadWidget;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CharaterStatus")
	FVector CurrentVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LowHealth")
	TSubclassOf<UUserWidget> LowHealthWidgetClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LowHealth")
	UUserWidget* LowHealthWidgetInstance;

	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealth() const;

	UFUNCTION(BlueprintCallable, Category = "Health")
	void AddHealth(float Amount);

	void DisableCollision();
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "health")
	float MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "health")
	float Health;


	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual float TakeDamage(
		float DamageAmount,
		struct FDamageEvent const& DamageEvent,
		AController* EventInstigator,
		AActor* DamgeCauser
	) override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void HandleMoveForwardInput(const FInputActionValue& value);
	UFUNCTION()
	void HandleMoveRightInput(const FInputActionValue& value);
	UFUNCTION()
	void StartJump(const FInputActionValue& value);
	UFUNCTION()
	void StopJump(const FInputActionValue& value);
	UFUNCTION()
	void Look(const FInputActionValue& value);
	UFUNCTION()
	void StartSprint(const FInputActionValue& value);
	UFUNCTION()
	void StopSprint(const FInputActionValue& value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	USoundBase* DeepBreathSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	USoundBase* HurtSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	USoundBase* ReliefSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	USoundBase* DeathSound;

	void OnDeath();
	
	void UpdateOverheadHP();
private:

	float NormalSpeed;
	float SprintSpeedMultiplier;
	float SprintSpeed;
	float MoveForwardInput;
	float RotationSpeed;
	float CurrentSpeed;
	float MinimumSpeed;
	FVector2D MoveRightInput;
	FRotator LookRotation;
	FRotator CameraRotation;
};
