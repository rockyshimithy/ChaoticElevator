// Fill out your copyright notice in the Description page of Project Settings.


#include "Block.h"

// Sets default values
ABlock::ABlock()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bIsColorChangeable = true;

	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("'/Game/Assets/Materials/M_Red.M_Red'"));
	if (Material.Succeeded())
	{
		MaterialBox = Material.Object;
		VisualMesh->SetMaterial(0, Material.Object);
		VisualMesh->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
		VisualMesh->SetupAttachment(RootComponent);
	}

	this->BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ABlock::ChangeColor);
}


void ABlock::ChangeColor(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("ChangeColor"));
	}
}

// Called when the game starts or when spawned
void ABlock::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}