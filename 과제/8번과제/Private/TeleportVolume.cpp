#include "TeleportVolume.h"
#include "Components/BoxComponent.h"

ATeleportVolume::ATeleportVolume()
{
 
    PrimaryActorTick.bCanEverTick = false;

    Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
    SetRootComponent(Scene);

    TeleportBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TeleportBox"));
    TeleportBox->SetupAttachment(Scene);

}

FVector ATeleportVolume::GetRandomPointInVolume() const
{
    FVector BoxExtend = TeleportBox->GetScaledBoxExtent();
    FVector BoxOrigin = TeleportBox->GetComponentLocation();

    return BoxOrigin + FVector(
        FMath::FRandRange(-BoxExtend.X, BoxExtend.X),
        FMath::FRandRange(-BoxExtend.Y, BoxExtend.Y),
        FMath::FRandRange(-BoxExtend.Z, BoxExtend.Z)
    );
}
