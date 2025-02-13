#include "CoinItem.h"
#include "Engine/World.h"
#include "SpartaGameState.h"

ACoinItem::ACoinItem()
{
	PrimaryActorTick.bCanEverTick = true;

	RotationSpeedYaw = 60.0f;
	RotationSpeedPitch = 0.0f;
	RotationSpeedRoll = 0.0f;
	PointValue = 0;
	ItemType = "DefaultCoin";
}

void ACoinItem::BeginPlay()
{
	Super::BeginPlay();

}

void ACoinItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeedYaw) || !FMath::IsNearlyZero(RotationSpeedPitch) || !FMath::IsNearlyZero(RotationSpeedRoll))
	{

		AddActorLocalRotation(FRotator(RotationSpeedPitch * DeltaTime, RotationSpeedYaw * DeltaTime, RotationSpeedRoll * DeltaTime));
	}
}

void ACoinItem::ActivateItem(AActor* Activator)
{
	Super::ActivateItem(Activator);

	if (Activator && Activator->ActorHasTag("Player"))
	{
		if (UWorld* Wolrd = GetWorld())
		{
			if (ASpartaGameState* GameState = Wolrd->GetGameState<ASpartaGameState>())
			{
				GameState->AddScore(PointValue);
				GameState->OnCoinCollected();
			}
		}
		DestroyItem();
	}
}
