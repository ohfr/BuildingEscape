// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	InitialYaw = GetOwner()->GetActorRotation().Yaw;
	CurrentYaw = InitialYaw;
	TargetYaw += InitialYaw;


}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// float myFloat = 90.f;

	// FRotator CurrentRotation = GetOwner()->GetActorRotation();

	// CurrentRotation.Yaw = myFloat;
	
	// FRotator OpenDoor{ 0.f, 90.f, 0.f}; this would work as well

	// GetOwner()->SetActorRotation(CurrentRotation);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *GetOwner()->GetActorRotation().ToString());
	UE_LOG(LogTemp, Warning, TEXT("%f"), GetOwner()->GetActorRotation().Yaw);

	// float CurrentYaw = GetOwner()->GetActorRotation().Yaw;

	// FRotator OpenDoor{0.f, TargetYaw, 0.f};

	// //change Yaw of OpenDoor
	// OpenDoor.Yaw =  FMath::Lerp(/*CurrentYaw, TargetYaw, 0-1*/CurrentYaw, TargetYaw, .02f);
	// // FMath::FInterpConstantTo(CurrentYaw, TargetYaw, DeltaTime, 45); // no easing,  45 degrees per second to targetYaw
	// // FMath::FInterpTo(CurrentYaw, TargetYaw, DeltaTime, 2); //easing at end, framerate independeant(Via DeltaTime)
	// GetOwner()->SetActorRotation(OpenDoor);


	CurrentYaw = FMath::Lerp(CurrentYaw, TargetYaw, 0.02f);

	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	//set Actor Rotation
	GetOwner()->SetActorRotation(DoorRotation);

}

