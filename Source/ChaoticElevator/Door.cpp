// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

ADoor::ADoor()
{
	VisualMesh->SetSimulatePhysics(false);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>DoorMesh(TEXT("'/Game/Assets/Door/Props/SM_Door.SM_Door'"));
	if (DoorMesh.Succeeded())
	{
		VisualMesh->SetStaticMesh(DoorMesh.Object);
		VisualMesh->SetRelativeScale3D(FVector(1.5f, 1.7f, 1.5f));
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialDoor(TEXT("'/Game/Assets/Door/Props/Materials/M_Door.M_Door'"));
	if (MaterialDoor.Succeeded())
	{
		VisualMesh->SetMaterial(0, MaterialDoor.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialGlass(TEXT("'/Game/Assets/Door/Materials/M_Glass.M_Glass'"));
	if (MaterialGlass.Succeeded())
	{
		VisualMesh->SetMaterial(1, MaterialGlass.Object);
	}

	BoxComponent->SetBoxExtent(FVector(5, 45, 100), false);
	BoxComponent->SetRelativeLocation(FVector(0.0f, -45.0f, 100.0f));
	BoxComponent->SetCollisionProfileName(FName("BlockAll"), false);

}

void ADoor::BeginPlay()
{
	Super::BeginPlay();
}

void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
