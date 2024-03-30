// Fill out your copyright notice in the Description page of Project Settings.

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
	// Sets default values for this actor's properties
	ABlockBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VisualMesh;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxComponent;

	UPROPERTY(VisibleAnywhere);
	UMaterial* MaterialBox;

	UPROPERTY(VisibleAnywhere)
	bool bIsColorChangeable;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
