// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealTech.h"
#include "MusicPlayerContainer.h"


// Sets default values
AMusicPlayerContainer::AMusicPlayerContainer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMusicPlayerContainer::BeginPlay()
{
	Super::BeginPlay();
	TArray<FString> foundFiles;
	FString songFolderPath = FPaths::GameUserDir();
	const TCHAR* characterArray = *songFolderPath;

	IFileManager::Get().FindFiles(foundFiles, characterArray);
	int32 path;
	path = foundFiles.Num();
	UE_LOG(LogTemp, Warning, TEXT("THE FILE PATH IS %d"), path);


	
}

// Called every frame
void AMusicPlayerContainer::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

