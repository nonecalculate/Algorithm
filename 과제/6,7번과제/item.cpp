#include "item.h"

Aitem::Aitem()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);


	PrimaryActorTick.bCanEverTick = true;

	RotationSpeed = 90.0f;

}


void Aitem::BeginPlay() 
{
	Super::BeginPlay();

}

void Aitem::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}

}


void Aitem::ResetActorPosition()
{
	SetActorLocation(FVector::ZeroVector);
}

float Aitem::GetRotationSpeed() const
{
	return RotationSpeed;
}