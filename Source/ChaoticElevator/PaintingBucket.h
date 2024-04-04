#pragma once

#include "CoreMinimal.h"
#include "BlockBase.h"
#include "PaintingBucket.generated.h"

UCLASS()
class CHAOTICELEVATOR_API APaintingBucket : public ABlockBase
{
	GENERATED_BODY()

public:
	APaintingBucket();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
};
