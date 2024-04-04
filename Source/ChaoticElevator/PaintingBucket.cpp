
#include "PaintingBucket.h"

APaintingBucket::APaintingBucket()
{
	VisualMesh->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));

	static ConstructorHelpers::FObjectFinder<UStaticMesh>CylinderMesh(TEXT("'/Engine/BasicShapes/Cylinder.Cylinder'"));
	if (CylinderMesh.Succeeded())
	{
		VisualMesh->SetStaticMesh(CylinderMesh.Object);
	}
}

void APaintingBucket::BeginPlay()
{
	Super::BeginPlay();
}

void APaintingBucket::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}