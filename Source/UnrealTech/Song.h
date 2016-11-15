// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "SongContainer.h"
#include "Song.generated.h"

/**
 * 
 */
UCLASS()
class UNREALTECH_API USong : public UUserWidget
{
	GENERATED_BODY()
public:
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USoundWave* loadedSong;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<ASongContainer> loadedSongContainer;
		UFUNCTION(BlueprintCallable, Category = "Song")
		void AttachSongToHand(USceneComponent* attachPoint);
	
	
};
