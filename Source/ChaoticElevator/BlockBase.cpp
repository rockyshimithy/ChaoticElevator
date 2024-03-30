// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockBase.h"

// Sets default values
ABlockBase::ABlockBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>CubeMesh(TEXT("'/Engine/BasicShapes/Cube.Cube'"));
	if (CubeMesh.Succeeded())
	{
		VisualMesh->SetStaticMesh(CubeMesh.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

	static ConstructorHelpers::FObjectFinder<UMaterial>Material(TEXT("'/Game/Assets/Materials/M_White.M_White'"));
	if (Material.Succeeded())
	{
		MaterialBox = Material.Object;
		VisualMesh->SetMaterial(0, MaterialBox);
		VisualMesh->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
		VisualMesh->SetupAttachment(RootComponent);
	}

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	VisualMesh->SetSimulatePhysics(true);
	BoxComponent->SetBoxExtent(FVector(52, 52, 52), false);
	BoxComponent->SetGenerateOverlapEvents(true);
	BoxComponent->SetupAttachment(VisualMesh);
	//BoxComponent->bMultiBodyOverlap = true;

	bIsColorChangeable = false;
}

// Called when the game starts or when spawned
void ABlockBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlockBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

