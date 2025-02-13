#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotationItem.generated.h"

UCLASS()
class SPARTAP_API ARotationItem : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotationItem();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "RotationItem|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotationItem|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotationItem|Properties")
	float RotationSpeedPitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotationItem|Properties")
	float RotationSpeedYaw;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotationItem|Properties")
	float RotationSpeedRoll;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


};
