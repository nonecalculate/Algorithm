#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "CoinItem.generated.h"


UCLASS()
class SPARTAP_API ACoinItem : public ABaseItem
{
	GENERATED_BODY()

public:
	ACoinItem();

protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 PointValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotationItem|Properties")
	float RotationSpeedPitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotationItem|Properties")
	float RotationSpeedYaw;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotationItem|Properties")
	float RotationSpeedRoll;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void ActivateItem(AActor* Activator) override;
};
