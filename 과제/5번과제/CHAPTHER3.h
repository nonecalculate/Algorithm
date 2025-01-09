#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor2.generated.h"

UCLASS()
class Q_API AMyActor2 : public AActor
{
	GENERATED_BODY()


public:
	AMyActor2();
protected:
	virtual void BeginPlay() override;
public:
	UPROPERTY()
	FVector2D start;

	UPROPERTY()
	int32 eventCount;

	UPROPERTY()
	float totalDist;

	UFUNCTION()
	void move();

	UFUNCTION()
	int32 step(); 

	UFUNCTION()
	float Dist(FVector2D first, FVector2D second);

	UFUNCTION()
	int32 createEvent();

};
