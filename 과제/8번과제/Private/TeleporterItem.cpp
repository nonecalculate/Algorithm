#include "TeleporterItem.h"
#include "SpartaCharacter.h"
#include "TeleportVolume.h"
#include "Kismet/GameplayStatics.h"


ATeleporterItem::ATeleporterItem()
{

}

void ATeleporterItem::ActivateItem(AActor* Activator)
{
    Super::ActivateItem(Activator); // BaseItem�� ActivateItem ���� ȣ��

    FVector TeleportLocation = GetTeleportLocation(Activator);

    if (Activator && Activator->IsA(ASpartaCharacter::StaticClass())) // �÷��̾� ĳ�������� Ȯ��
    {
        ASpartaCharacter* PlayerCharacter = Cast<ASpartaCharacter>(Activator);
        if (PlayerCharacter)
        {
            PlayerCharacter->TeleportTo(TeleportLocation, FRotator::ZeroRotator); // �ڷ���Ʈ ����
        }
    }

    DestroyItem();
}

FVector ATeleporterItem::GetTeleportLocation(AActor* Activator)
{
    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATeleportVolume::StaticClass(), FoundActors);

    if (FoundActors.Num() > 0)
    {
        int32 RandomIndex = FMath::RandRange(0, FoundActors.Num() - 1);
        ATeleportVolume* RandomTeleportVolume = Cast<ATeleportVolume>(FoundActors[RandomIndex]);
        if (RandomTeleportVolume)
        {
            return RandomTeleportVolume->GetRandomPointInVolume();
        }

    }


    UE_LOG(LogTemp, Warning, TEXT("TeleportVolume not found!"));
    return Activator->GetActorLocation();
}