// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldPosition.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UWorldPosition::UWorldPosition()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWorldPosition::BeginPlay()
{
	Super::BeginPlay();

	// logs accessible in developer tools -> output log
		// UE_LOG(LogTemp, Display, TEXT("This is just a display"));
		// UE_LOG(LogTemp, Warning, TEXT("This is a warning!"));
		// UE_LOG(LogTemp, Error, TEXT("This is an Error"));

	// FString Log = TEXT("Hello");
	// FString* PtrLog = &Log; // & as an expressions means address

	// PtrLog->Len() // same as (*PtrLog).Len();
	// UE_LOG(LogTemp, Warning, TEXT("%s"), **PtrLog); // dereference and overload PtrLog

	FString ObjectName = GetOwner()->GetName(); // get actor name

	// UE_LOG(LogTemp, Warning, TEXT("%s"), *ObjectName);

	FString ObjectPosition = GetOwner()->GetActorLocation().ToString();

	UE_LOG(LogTemp, Warning, TEXT("Position in world is: %s"), *ObjectPosition);
}


// Called every frame
void UWorldPosition::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

