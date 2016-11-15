// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "SoundLoadingMenu.generated.h"

/**
 * 
 */
UCLASS()
class UNREALTECH_API USoundLoadingMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// Needs to be called by another blueprint or class to initalize
	 void BeginPlay();
	 void GenerateLoadedSongList(UPanelWidget* parentTransform);
	USoundWave* GetSoundWaveFromFile(const FString& filePath)
	{
		USoundWave* sw = NewObject<USoundWave>(USoundWave::StaticClass());

		if (!sw)
			return nullptr;

		TArray < uint8 > rawFile;

		FFileHelper::LoadFileToArray(rawFile, filePath.GetCharArray().GetData());
		FWaveModInfo WaveInfo;

		if (WaveInfo.ReadWaveInfo(rawFile.GetData(), rawFile.Num()))
		{
			sw->InvalidateCompressedData();

			sw->RawData.Lock(LOCK_READ_WRITE);
			void* LockedData = sw->RawData.Realloc(rawFile.Num());
			FMemory::Memcpy(LockedData, rawFile.GetData(), rawFile.Num());
			sw->RawData.Unlock();

			int32 DurationDiv = *WaveInfo.pChannels * *WaveInfo.pBitsPerSample * *WaveInfo.pSamplesPerSec;
			if (DurationDiv)
			{
				sw->Duration = *WaveInfo.pWaveDataSize * 8.0f / DurationDiv;
			}
			else
			{
				sw->Duration = 0.0f;
			}
			sw->SampleRate = *WaveInfo.pSamplesPerSec;
			sw->NumChannels = *WaveInfo.pChannels;
			sw->RawPCMDataSize = WaveInfo.SampleDataSize;
			sw->SoundGroup = ESoundGroup::SOUNDGROUP_Default;
		}
		else {
			return nullptr;
		}

		return sw;
	}

	
	
};
