// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealTech.h"
#include "MotionControllerPawn.h"


// Sets default values
AMotionControllerPawn::AMotionControllerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMotionControllerPawn::BeginPlay()
{
	TArray<FString> foundFiles;
	FString songFolderPath = FPaths::GameUserDir() + "StoredSongs";
	UE_LOG(LogTemp, Warning, TEXT("THE NUMBER OF FILES IS %s"), *songFolderPath);
	const TCHAR* characterArray = *songFolderPath;
	const TCHAR* fileExtension = TEXT(".wav");
	IFileManager::Get().FindFiles(foundFiles, characterArray,fileExtension);
	int32 path;
	path = foundFiles.Num();
	UE_LOG(LogTemp, Warning, TEXT("THE NUMBER OF FILES IS %d"), path);
	UE_LOG(LogTemp, Warning, TEXT(" %s"), *foundFiles[0]);

	for (int i = 0; i < foundFiles.Num(); i++)
	{
		loadedSounds.Add(GetSoundWaveFromFile(FPaths::GameUserDir() + "StoredSongs/" + foundFiles[i]));
	}

	Super::BeginPlay();
}

// Called every frame
void AMotionControllerPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AMotionControllerPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

