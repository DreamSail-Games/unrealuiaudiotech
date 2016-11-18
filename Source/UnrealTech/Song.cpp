// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealTech.h"
#include "Song.h"




AActor* USong::AttachSongToHand(USceneComponent* attachPoint)
{
	FActorSpawnParameters SpawnParams;
	FVector location = attachPoint->GetComponentTransform().GetLocation();
	FRotator rotation = attachPoint->GetComponentTransform().Rotator();
	ASongContainer* songContainerActor = (ASongContainer*)GetWorld()->SpawnActor<ASongContainer>(loadedSongContainer, location, rotation, SpawnParams);
	songContainerActor->loadedSound = loadedSong;
	UStaticMeshComponent* mesh = Cast<UStaticMeshComponent>(songContainerActor->GetRootComponent());
	mesh->SetSimulatePhysics(false);
	FAttachmentTransformRules attachRules = FAttachmentTransformRules::KeepRelativeTransform;
	mesh->AttachToComponent(attachPoint,attachRules);
	return Cast<AActor>(songContainerActor);
}