#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DissapearItem.generated.h"

UCLASS()
class SPARTAP_API ADissapearItem : public AActor
{
	GENERATED_BODY()
	
public:	
	ADissapearItem();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="DisappearItem|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category="DisappearItem|Components")
	UStaticMeshComponent* StaticMeshComp;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DisappearItem|Properties")
	float ExistTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DisappearItem|Properties")
	float NoneExistTime;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "DisappearItem|Properties")
	bool InVisible;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "DisappearItem|Properties")
	float TempTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DisappearItem|Properties")
	float ApearInGameTime;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "DisappearItem|Properties")
	float TempApearTime;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
