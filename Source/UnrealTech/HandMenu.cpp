// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealTech.h"
#include "HandMenu.h"


void UHandMenu::CreatePlayer(AActor* player)
{

	UE_LOG(LogTemp, Warning, TEXT("Trying to create a player"));
	FActorSpawnParameters SpawnParams;
	FVector location = player->GetActorLocation();
	FRotator rotation = player->GetActorRotation();
	AMusicPlayerContainer* myRef = GetWorld()->SpawnActor<AMusicPlayerContainer>(MusicPlayerBP, location,rotation, SpawnParams);
}
