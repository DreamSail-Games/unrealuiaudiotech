// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealTech.h"
#include "HandMenu.h"


void UHandMenu::CreatePlayer(USceneComponent* handComponent)
{
	FActorSpawnParameters SpawnParams;
	FVector location = handComponent->GetComponentTransform().GetLocation();
	FRotator rotation = handComponent->GetComponentTransform().Rotator();
	AMusicPlayerContainer* myRef = (AMusicPlayerContainer*)GetWorld()->SpawnActor<AMusicPlayerContainer>(MusicPlayerBP, location,rotation, SpawnParams);
}
