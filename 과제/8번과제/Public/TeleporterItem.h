#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "TeleporterItem.generated.h"


UCLASS()
class SPARTAP_API ATeleporterItem : public ABaseItem
{
	GENERATED_BODY()
public:
	ATeleporterItem();

	virtual void ActivateItem(AActor* Activator) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Teleport")
	float TeleportRadius;

	FVector GetTeleportLocation(AActor* Activator);

};
