#include "BigCoinItem.h"

ABigCoinItem::ABigCoinItem()
{
	PointValue = 50;
	ItemType = "BFCoin";
}

void ABigCoinItem::ActivateItem(AActor* Activator) 
{
	Super::ActivateItem(Activator);
}

