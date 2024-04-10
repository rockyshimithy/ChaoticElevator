#pragma once

#include "CoreMinimal.h"
#include "BlockBase.h"
#include "Door.generated.h"

UCLASS()
class CHAOTICELEVATOR_API ADoor : public ABlockBase
{
	GENERATED_BODY()

public:
	ADoor();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
};
