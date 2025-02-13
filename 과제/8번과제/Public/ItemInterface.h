#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ItemInterface.generated.h"

UINTERFACE(MinimalAPI)
class UItemInterface : public UInterface
{
	GENERATED_BODY()
};

class SPARTAP_API IItemInterface
{
	GENERATED_BODY()


public:
	UFUNCTION()
	virtual void OnItemOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult) = 0; // 뒤에 = 0 이 붙는 이유는 이 함수는 무조건 오버라이딩 하라는 의미. 즉, 이 인터페이스를 쓰는 클래스는 무조건 이 함수가 존재해야한다는 의미이다. 인터페이스를 쓰기에 보통 모두 0으로 놓는게 맞다.
	UFUNCTION()
	virtual void OnItemEndOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex ) = 0;
	virtual void ActivateItem(AActor* Activator) = 0;
	virtual FName GetItemType() const = 0; // String 보다는 FName 을 쓰는게 더 빠르고 가벼움

};
