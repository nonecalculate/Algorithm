// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class STEPDIALGOUE_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	

	AMyActor();

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
	float Dist(FVector2D f, FVector2D s);

	UFUNCTION()
	int32 createEvent();

};
