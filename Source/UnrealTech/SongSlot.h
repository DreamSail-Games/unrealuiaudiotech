// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "Song.h"
#include "SongSlot.generated.h"

/**
 * 
 */
UCLASS()
class UNREALTECH_API USongSlot : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<UUserWidget> WidgetTemplate;

	UPROPERTY()
		UUserWidget* WidgetInstance;
	UFUNCTION(BlueprintCallable, Category = "Song")
	void GenerateSong(UPanelWidget* parentTransform, USong* loadedSong);

	UFUNCTION(BlueprintCallable, Category = "Song")
		void RemoveSong(UPanelWidget* parentTransform);
};
