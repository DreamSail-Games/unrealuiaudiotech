// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealTech.h"
#include "SongSlot.h"




void USongSlot::GenerateSong(UPanelWidget* parentTransform,USong* loadedSong)
{
	WidgetInstance = CreateWidget<UUserWidget>(GetWorld(), WidgetTemplate);
	parentTransform->AddChild(WidgetInstance);
	USong* thisSong = Cast<USong>(WidgetInstance);
	if (thisSong)
	{
		thisSong->loadedSong = loadedSong->loadedSong;
	}
}

void USongSlot::RemoveSong(UPanelWidget* parentTransform)
{

	parentTransform->ClearChildren();
}