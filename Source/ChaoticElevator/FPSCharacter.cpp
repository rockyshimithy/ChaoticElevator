
#include "FPSCharacter.h"

AFPSCharacter::AFPSCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	check(FPSCameraComponent != nullptr); // Do I really need it here?
	FPSCameraComponent->SetupAttachment(CastChecked<USceneComponent, UCapsuleComponent>(GetCapsuleComponent()));
	// Position the camera slightly above the eyes. Should we?
	FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));
	FPSCameraComponent->bUsePawnControlRotation = true;

	FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
	check(FPSMesh != nullptr);  // Do I really need it here?
	FPSMesh->SetOnlyOwnerSee(true);
	FPSMesh->SetupAttachment(FPSCameraComponent);
	FPSMesh->bCastDynamicShadow = false; // Disable some environmental shadows to preserve the illusion of having a single mesh.
	FPSMesh->CastShadow = false; // The owning player doesn't see the regular (third-person) body mesh.
	GetMesh()->SetOwnerNoSee(true);

	bIsGrabbingObject = false; // What about use PhysicsHandle->GrabbedComponent only?

	PhysicsHandle = CreateDefaultSubobject<UPhysicsHandleComponent>(TEXT("PhysicsHandle"));
}

void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PhysicsHandle->GrabbedComponent)
	{
		FVector CameraLocation;
		FRotator CameraRotation;
		GetActorEyesViewPoint(CameraLocation, CameraRotation);

		FVector TraceEnd = CameraLocation + FTransform(CameraRotation).TransformVector(FVector(250.0f, 0.0, 0.0f));

		PhysicsHandle->SetTargetLocation(TraceEnd);
	}
}

void AFPSCharacter::MoveForward(float Value)
{
	//AddMovementInput(GetActorForwardVector(), Value);

	// Find out which way is "forward" and record that the player wants to move that way.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void AFPSCharacter::MoveRight(float Value)
{
	//AddMovementInput(GetActorRightVector(), Value);

	// Find out which way is "right" and record that the player wants to move that way.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void AFPSCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void AFPSCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void AFPSCharacter::Fire()
{
	//// Attempt to fire a projectile.
	//if (ProjectileClass)
	//{
	//	// Get the camera transform.
	//	FVector CameraLocation;
	//	FRotator CameraRotation;
	//	GetActorEyesViewPoint(CameraLocation, CameraRotation);

	//	// Set MuzzleOffset to spawn projectiles slightly in front of the camera.
	//	MuzzleOffset.Set(100.0f, 0.0f, 0.0f);

	//	// Transform MuzzleOffset from camera space to world space.
	//	FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset);

	//	// Skew the aim to be slightly upwards.
	//	FRotator MuzzleRotation = CameraRotation;
	//	MuzzleRotation.Pitch += 2.5f;				// not sure about this value as well as about the MuzzleLocation

	//	UWorld* World = GetWorld();
	//	if (World)
	//	{
	//		FActorSpawnParameters SpawnParams;
	//		SpawnParams.Owner = this;
	//		SpawnParams.Instigator = GetInstigator();

	//		// Spawn the projectile at the muzzle.
	//		AFPSProjectile* Projectile = World->SpawnActor<AFPSProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
	//		if (Projectile)
	//		{
	//			// Set the projectile's initial trajectory.
	//			FVector LaunchDirection = MuzzleRotation.Vector();
	//			Projectile->FireInDirection(LaunchDirection);
	//		}
	//	}
	//}
}

void AFPSCharacter::PickUpObject()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("PickUpObject"));
	if (!bIsGrabbingObject)
	{
		FHitResult Hit;

		FVector CameraLocation;
		FRotator CameraRotation;
		GetActorEyesViewPoint(CameraLocation, CameraRotation);

		FVector TraceStart = CameraLocation;
		FVector TraceEnd = CameraLocation + FTransform(CameraRotation).TransformVector(FVector(250.0f, 0.0, 0.0f));

		FCollisionQueryParams QueryParams;
		QueryParams.AddIgnoredActor(this);

		GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, TraceChannelProperty, QueryParams);

		DrawDebugLine(GetWorld(), TraceStart, TraceEnd, Hit.bBlockingHit ? FColor::Blue : FColor::Red, false, 5.0f, 0, 2.0f);

		if (Hit.bBlockingHit && IsValid(Hit.GetActor()))
		{
			UE_LOG(LogTemp, Log, TEXT("Trace hit actor: %s"), *Hit.GetActor()->GetName());

			UPrimitiveComponent* Component = Hit.GetComponent();
			PhysicsHandle->GrabComponentAtLocationWithRotation(
				Component,
				NAME_None,
				Component->GetRelativeTransform().GetTranslation(),
				Component->GetRelativeTransform().GetRotation().Rotator()
			);

			bIsGrabbingObject = true;
		}

	}
	else
	{
		PhysicsHandle->ReleaseComponent();
		bIsGrabbingObject = false;
	}
}


void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Review input system...
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("ForwardAxis", this, &AFPSCharacter::MoveForward);
	PlayerInputComponent->BindAxis("RightAxis", this, &AFPSCharacter::MoveRight);

	PlayerInputComponent->BindAxis("LookUp", this, &AFPSCharacter::LookUp);
	PlayerInputComponent->BindAxis("Turn", this, &AFPSCharacter::Turn);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AFPSCharacter::Fire);
	PlayerInputComponent->BindAction("PickUpObject", IE_Pressed, this, &AFPSCharacter::PickUpObject);
}

