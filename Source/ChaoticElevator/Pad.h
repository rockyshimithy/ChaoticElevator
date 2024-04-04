#pragma once

#include "CoreMinimal.h"
#include "BlockBase.h"
#include "Pad.generated.h"

UCLASS()
class CHAOTICELEVATOR_API APad : public ABlockBase
{
	GENERATED_BODY()

public:
	APad();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void Unlock(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void Lock(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	virtual void BeginPlay() override;
};
