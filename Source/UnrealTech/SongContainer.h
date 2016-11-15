// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SongContainer.generated.h"

UCLASS()
class UNREALTECH_API ASongContainer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASongContainer();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundWave* loadedSound;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
