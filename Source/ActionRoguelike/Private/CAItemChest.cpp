// Fill out your copyright notice in the Description page of Project Settings.


#include "CAItemChest.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ACAItemChest::ACAItemChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TargetPitch = 110;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	RootComponent = BaseMesh;

	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>("LidMesh");
	LidMesh->SetupAttachment(BaseMesh);
}

// Called when the game starts or when spawned
void ACAItemChest::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACAItemChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACAItemChest::Interact_Implementation(APawn* InstigatingPawn)
{
	LidMesh->SetRelativeRotation(FRotator(TargetPitch, 0, 0));
}

