#include "RotationItem.h"

ARotationItem::ARotationItem()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;

	RotationSpeedYaw = 60.0f;
	RotationSpeedPitch = 60.0f;
	RotationSpeedRoll = 60.0f;
}

void ARotationItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARotationItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeedYaw)|| !FMath::IsNearlyZero(RotationSpeedPitch)|| !FMath::IsNearlyZero(RotationSpeedRoll))
	{

		AddActorLocalRotation(FRotator(RotationSpeedPitch * DeltaTime, RotationSpeedYaw * DeltaTime, RotationSpeedRoll * DeltaTime));
	}
}
