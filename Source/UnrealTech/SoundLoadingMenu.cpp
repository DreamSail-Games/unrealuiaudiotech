// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealTech.h"
#include "SoundLoadingMenu.h"




void USoundLoadingMenu::BeginPlay()
{
	TArray<FString> foundFiles;
	FString songFolderPath = FPaths::GameUserDir();
	const TCHAR* characterArray = *songFolderPath;

	IFileManager::Get().FindFiles(foundFiles, characterArray);
	int32 path;
	path = foundFiles.Num();
	//UE_LOG(LogTemp, Warning, TEXT("THE FILE PATH IS %d"), path);


}

void USoundLoadingMenu::GenerateLoadedSongList(UPanelWidget* parentTransform)
{

	TArray<FString> foundFiles;
	TArray<USoundWave*> loadedSounds;
	FString songFolderPath = FPaths::GameUserDir() + "StoredSongs";
	UE_LOG(LogTemp, Warning, TEXT("THE NUMBER OF FILES IS %s"), *songFolderPath);
	const TCHAR* characterArray = *songFolderPath;
	const TCHAR* fileExtension = TEXT(".wav");
	IFileManager::Get().FindFiles(foundFiles, characterArray, fileExtension);
	int32 path;
	path = foundFiles.Num();
	UE_LOG(LogTemp, Warning, TEXT("THE NUMBER OF FILES IS %d"), path);
	UE_LOG(LogTemp, Warning, TEXT(" %s"), *foundFiles[0]);

	for (int i = 0; i < foundFiles.Num(); i++)
	{
		loadedSounds.Add(GetSoundWaveFromFile(FPaths::GameUserDir() + "StoredSongs/" + foundFiles[i]));
	}

	for (int i = 0; i < loadedSounds.Num(); i++)
	{
		WidgetInstance = CreateWidget<UUserWidget>(GetWorld(), WidgetTemplate);
		parentTransform->AddChild(WidgetInstance);
		USong* thisSong = Cast<USong>(WidgetInstance);
		if (thisSong)
		{
			const TCHAR* name = *foundFiles[i];
			thisSong->loadedSong = loadedSounds[i];
			thisSong->Rename(name);
		}
	}
}