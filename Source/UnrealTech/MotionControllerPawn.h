// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "MotionControllerPawn.generated.h"

UCLASS()
class UNREALTECH_API AMotionControllerPawn : public APawn
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<USoundWave*> loadedSounds;

	// Sets default values for this pawn's properties
	AMotionControllerPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
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
