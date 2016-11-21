// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "MusicPlayer.generated.h"

/**
 * 
 */
UCLASS()
class UNREALTECH_API UMusicPlayer : public UUserWidget
{
	GENERATED_BODY()
	
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPanelWidget* parentTransform;
	

};
