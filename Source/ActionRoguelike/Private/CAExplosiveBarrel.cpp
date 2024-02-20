// Fill out your copyright notice in the Description page of Project Settings.


#include "CAExplosiveBarrel.h"
#include "PhysicsEngine/RadialForceComponent.h"

// Sets default values
ACAExplosiveBarrel::ACAExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BarrelMesh = CreateDefaultSubobject<UStaticMeshComponent>("Barrel");
	BarrelMesh->SetSimulatePhysics(true);
	BarrelMesh->SetCollisionProfileName("PhysicsActor");
	BarrelMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	RootComponent = BarrelMesh;

	BarrelMesh->OnComponentHit.AddDynamic(this, &ACAExplosiveBarrel::OnBarrelHit);

	RadialForceComponent = CreateDefaultSubobject<URadialForceComponent>("Radial Force Component");
	RadialForceComponent->SetupAttachment(BarrelMesh);
}

void ACAExplosiveBarrel::OnBarrelHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	RadialForceComponent->FireImpulse();
}


// Called when the game starts or when spawned
void ACAExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACAExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

