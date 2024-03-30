// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BlockBase.h"
#include "Block.generated.h"

/**
 * 
 */
UCLASS()
class CHAOTICELEVATOR_API ABlock : public ABlockBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABlock();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void ChangeColor(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
