
#include "Block.h"
#include "PaintingBucket.h"

ABlock::ABlock()
{
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ABlock::ChangeColor);
}

void ABlock::BeginPlay()
{
	Super::BeginPlay();
}

void ABlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABlock::ChangeColor(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		if (OtherActor->IsA(APaintingBucket::StaticClass())) {
			APaintingBucket* PaintingBucket = Cast<APaintingBucket>(OtherActor);
			VisualMesh->SetMaterial(0, PaintingBucket->VisualMesh->GetMaterial(0));
		}
	}
}