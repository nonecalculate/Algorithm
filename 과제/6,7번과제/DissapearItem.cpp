#include "DissapearItem.h"

ADissapearItem::ADissapearItem()
{

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;

	ExistTime = 0.0f;
	NoneExistTime = 0.0f;
	TempTime = 0.0f;
	ApearInGameTime = 0.0f;
	TempApearTime = 0.0f;
	InVisible = true;
	StaticMeshComp->SetCollisionProfileName("NoCollision");
	StaticMeshComp->SetHiddenInGame(InVisible);
}

void ADissapearItem::BeginPlay()
{
	Super::BeginPlay();

}

void ADissapearItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (TempApearTime <= ApearInGameTime) TempApearTime += DeltaTime;
	else 
	{
		if (!FMath::IsNearlyZero(ExistTime))
		{
			if (!InVisible)
			{
				if (TempTime >= ExistTime)
				{
					InVisible = true;
					StaticMeshComp->SetCollisionProfileName("NoCollision");
					StaticMeshComp->SetHiddenInGame(InVisible);
				}
				TempTime += DeltaTime;
			}
			else if (InVisible)
			{
				if (TempTime <= (ExistTime - NoneExistTime))
				{
					InVisible = false;
					StaticMeshComp->SetCollisionProfileName("BlockAllDynamic");
					StaticMeshComp->SetHiddenInGame(InVisible);
					TempTime = 0.0F;
				}
				TempTime -= DeltaTime;
			}
		}
	}
}
