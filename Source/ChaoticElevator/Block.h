#pragma once

#include "CoreMinimal.h"
#include "BlockBase.h"
#include "Block.generated.h"

UCLASS()
class CHAOTICELEVATOR_API ABlock : public ABlockBase
{
	GENERATED_BODY()

public:
	ABlock();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void ChangeColor(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	virtual void BeginPlay() override;
};
