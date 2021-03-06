// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "MusicPlayerContainer.h"
#include "HandMenu.generated.h"


/**
 * 
 */
UCLASS()
class UNREALTECH_API UHandMenu : public UUserWidget
{
	GENERATED_BODY()
		

	
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawnables")
	TSubclassOf<AActor> MusicPlayerBP;
	UFUNCTION(BlueprintCallable, Category = "HandMenu")
	void CreatePlayer(UPARAM(ref) USceneComponent* player);

	
};
