// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealTech.h"
#include "HandMenu.h"


void UHandMenu::CreatePlayer(USceneComponent* handComponent)
{
	FString path;
	path = FPaths::GameUserDir();
	UE_LOG(LogTemp, Warning,TEXT("THE FILE PATH IS %s"),*path);
	FActorSpawnParameters SpawnParams;
	FVector location = handComponent->GetComponentTransform().GetLocation();
	FRotator rotation = handComponent->GetComponentTransform().Rotator();
	AMusicPlayerContainer* myRef = (AMusicPlayerContainer*)GetWorld()->SpawnActor<AMusicPlayerContainer>(MusicPlayerBP, location,rotation, SpawnParams);
}
