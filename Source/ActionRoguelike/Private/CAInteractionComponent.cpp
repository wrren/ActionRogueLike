// Fill out your copyright notice in the Description page of Project Settings.


#include "CAInteractionComponent.h"

#include "CAGameplayInterface.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UCAInteractionComponent::UCAInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UCAInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Called every frame
void UCAInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCAInteractionComponent::PrimaryInteract()
{
	FCollisionObjectQueryParams ObjectQueryParams;
	ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);

	
	FVector		EyeLocation;
	FRotator	EyeRotator;

	GetOwner()->GetActorEyesViewPoint(EyeLocation, EyeRotator);

	FVector		End = EyeLocation + (EyeRotator.Vector() * 1000.0);

	FHitResult Hit;
	if(GetWorld()->LineTraceSingleByObjectType(Hit, EyeLocation, End, ObjectQueryParams))
	{
		const auto HitActor = Hit.GetActor();

		if(HitActor->Implements<UCAGameplayInterface>())
		{
			ICAGameplayInterface::Execute_Interact(HitActor, Cast<APawn>(GetOwner()));
		}
	}

	DrawDebugLine(GetWorld(), EyeLocation, End, FColor::Red, false, 2.0f, 0, 2.0f);
}