// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealTech.h"
#include "Song.h"




void USong::AttachSongToHand(USceneComponent* attachPoint)
{
	FActorSpawnParameters SpawnParams;
	FVector location = attachPoint->GetComponentTransform().GetLocation();
	FRotator rotation = attachPoint->GetComponentTransform().Rotator();
	ASongContainer* songContainerActor;
	songContainerActor = (ASongContainer*)GetWorld()->SpawnActor<ASongContainer>(loadedSongContainer, location, rotation, SpawnParams);

}