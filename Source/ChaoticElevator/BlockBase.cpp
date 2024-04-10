
#include "BlockBase.h"

ABlockBase::ABlockBase()
{
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	VisualMesh->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	VisualMesh->SetSimulatePhysics(true);
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>CubeMesh(TEXT("'/Engine/BasicShapes/Cube.Cube'"));
	if (CubeMesh.Succeeded())
	{
		VisualMesh->SetStaticMesh(CubeMesh.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("'/Game/Assets/Materials/M_White.M_White'"));
	if (Material.Succeeded())
	{
		VisualMesh->SetMaterial(0, Material.Object);

	}

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	BoxComponent->SetBoxExtent(FVector(52, 52, 52), false);
	BoxComponent->SetGenerateOverlapEvents(true);
	BoxComponent->SetupAttachment(VisualMesh);
	//BoxComponent->bMultiBodyOverlap = true;

}

void ABlockBase::BeginPlay()
{
	Super::BeginPlay();
}

void ABlockBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

