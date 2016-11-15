// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealTech.h"
#include "SongContainer.h"


// Sets default values
ASongContainer::ASongContainer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASongContainer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASongContainer::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

