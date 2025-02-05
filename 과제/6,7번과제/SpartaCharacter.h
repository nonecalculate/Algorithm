#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpartaCharacter.generated.h"


class USpringArmComponent;
class UCameraComponent;
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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CharaterStatus")
	FVector CurrentVelocity;

protected:

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

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

	virtual void Tick(float DeltaTime) override;

private:

	float NormalSpeed;
	float SprintSpeedMultiplier;
	float SprintSpeed;
	float MoveForwardInput;
	float RotationSpeed;
	float CurrentSpeed;
	FVector2D MoveRightInput;
	FRotator LookRotation;
	FRotator CameraRotation;
	FVector PreviousLocation;
};
