#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/BoxComponent.h>
#include "BlockBase.generated.h"

UCLASS()
class CHAOTICELEVATOR_API ABlockBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ABlockBase();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VisualMesh;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxComponent;

protected:
	virtual void BeginPlay() override;
};
