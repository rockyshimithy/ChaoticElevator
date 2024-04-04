
#include "Pad.h"

APad::APad()
{
	VisualMesh->SetRelativeScale3D(FVector(1.0f, 1.0f, 0.05f));
	VisualMesh->SetSimulatePhysics(false);

	BoxComponent->SetBoxExtent(FVector(50, 50, 75), false);
	BoxComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 25.0f));

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &APad::Unlock);
	BoxComponent->OnComponentEndOverlap.AddDynamic(this, &APad::Lock);
}

void APad::BeginPlay()
{
	Super::BeginPlay();
}

void APad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APad::Unlock(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("UnlockDoor"));
		// Check if it's unlocking door
	}
}

void APad::Lock(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("LockDoor"));
		// Check if it's locking door
	}
}