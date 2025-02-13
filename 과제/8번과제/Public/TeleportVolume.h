#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TeleportVolume.generated.h"

class UBoxComponent;
UCLASS()
class SPARTAP_API ATeleportVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	ATeleportVolume();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Teleport")
	USceneComponent* Scene;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Teleport")
	UBoxComponent* TeleportBox;

	FVector GetRandomPointInVolume() const;

};
