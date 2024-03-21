// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharacter.h"

// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Move Character Forward and Backwards
void AFPSCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

// Move Character to Right or Left
void AFPSCharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

void AFPSCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void AFPSCharacter::LookRight(float Value)
{
	AddControllerYawInput(Value);
}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("ForwardAxis", this, &AFPSCharacter::MoveForward);
	PlayerInputComponent->BindAxis("RightAxis", this, &AFPSCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AFPSCharacter::LookUp);
	PlayerInputComponent->BindAxis("LookRight", this, &AFPSCharacter::LookRight);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
}

