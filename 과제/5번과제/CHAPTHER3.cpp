// 저장할때 utf-8로 인코딩이 되어있는지 확인할것. 아니면 언리얼에서 컴파일이 안됨

#include "MyActor.h"
#include "Math/UnrealMathUtility.h"
#include "Containers/Array.h"
#include "Engine/Engine.h"

AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = true;
	start = FVector2D(0, 0);
	eventCount = 0;
	totalDist = 0;

}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	move();
	UE_LOG(LogTemp, Warning, TEXT("총 이동 거리는 : %f 입니다"), totalDist);
	UE_LOG(LogTemp, Warning, TEXT("총 이동 발생 횟수는 : %d 입니다"), eventCount);
}

int32 AMyActor::step()
{
	return FMath::RandRange(0, 1);
}

float AMyActor::Dist(FVector2D f, FVector2D s)
{
	float dx = f.X - s.X;
	float dy = f.Y - s.Y;
	return FMath::Sqrt(dx * dx + dy * dy);
}

int32 AMyActor::createEvent() {
	int32 r = FMath::RandRange(1, 2);
	if (r == 1)
	{
		UE_LOG(LogTemp, Log, TEXT("이벤트가 발생했습니다!"));
		return 1;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("아직은 잠잠합니다..."));
		return 0;
	}
}

void AMyActor::move()
{
	FVector2D crt = start;
	FVector2D prv = crt;
	for (int32 i = 0; i < 10; i++)
	{
		FVector2D next(crt.X + step(), crt.Y + step());
		if (next.X - crt.X <= 2 && next.Y - crt.Y <= 2)
		{
			float dist = Dist(crt, next);
			totalDist += dist;
			UE_LOG(LogTemp, Warning, TEXT("%d번째 스텝입니다. 현재 좌표는 (%f,%f)이며 이동 거리는: %f 입니다."), i + 1, next.X, next.Y, dist);
			eventCount += createEvent();
			prv = crt;
			crt = next;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("다시 움직여야 합니다.."));
		}
	}

}

