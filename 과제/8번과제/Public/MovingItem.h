#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingItem.generated.h"

UCLASS()
class SPARTAP_API AMovingItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingItem();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="MovingItem|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MovingItem|Components")
	UStaticMeshComponent* StaticMeshComp;


	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category="MovingItem|Properties")
	float MoveXSpeed;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "MovingItem|Properties")
	float MoveYSpeed;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "MovingItem|Properties")
	float MoveZSpeed;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "MovingItem|Properties", meta = (DisplayName = "Movin Time", ToolTip = "It moves at a set speed per second. If you set the time to 2 and the speed to 150, it will move a total of 300 units."))
	float MoveTime;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "MovingItem|Properties", meta = (DisplayName = "Standing Time", ToolTip = "Once it arrives at the destination, it will halt for the specified amount of time."))
	float Delay;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MovingItem|Properties")
	bool IsEnd;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MovingItem|Properties")
	float CountMoveTime;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MovingItem|Properties")
	float CountDelay;


	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
