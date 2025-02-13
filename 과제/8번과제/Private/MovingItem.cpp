#include "MovingItem.h"

AMovingItem::AMovingItem()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;

	MoveXSpeed = 0.0f;
	MoveYSpeed = 0.0f;
	MoveZSpeed = 0.0f;
	MoveTime = 0.0f;
	Delay = 0.0f;
	CountMoveTime = 0.0f;
	CountDelay = 0.0f;
	IsEnd = false;
}

void AMovingItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMovingItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsEnd == false) 
	{
		if(CountMoveTime <= MoveTime) AddActorWorldOffset(FVector3d(MoveXSpeed * DeltaTime, MoveYSpeed * DeltaTime, MoveZSpeed * DeltaTime));
		CountMoveTime += DeltaTime;
		if (CountMoveTime >= MoveTime) 
		{
			CountDelay += DeltaTime;
			if (CountDelay >= Delay) 
			{
				CountMoveTime = MoveTime;
				IsEnd = true;
				CountDelay = 0.0f;
			}
		}
	}
	else if (IsEnd == true) 
	{
		if (CountMoveTime >= 0) AddActorWorldOffset(FVector3d(-MoveXSpeed * DeltaTime, -MoveYSpeed * DeltaTime, -MoveZSpeed * DeltaTime));
		CountMoveTime -= DeltaTime;
		if (CountMoveTime <=  0)
		{
			CountDelay += DeltaTime;
			if (CountDelay >= Delay)
			{
				CountMoveTime = 0;
				IsEnd = false;
				CountDelay = 0.0f;
			}
		}
	}

}
