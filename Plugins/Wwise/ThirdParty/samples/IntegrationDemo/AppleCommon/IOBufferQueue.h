//
//  IOBufferQueue.h
//  IntegrationDemo
//
//  Created by Build Master on 1/15/12.
//  Copyright (c) 2012 Audiokinetic Inc. All rights reserved.
//

#ifndef IntegrationDemo_IOBufferQueue_h
#define IntegrationDemo_IOBufferQueue_h

#include "stdafx.h"

#include <AK/SoundEngine/Common/AkCommonDefs.h>
#include <AK/SoundEngine/Common/AkTypes.h>
#include <AK/Tools/Common/AkLock.h>


#define AK_IO_BUFFER_COUNT 4

// NOTE: Currently only supports mono data.
// Sample size is equal to audio format byte size.
// The buffer is shared by Wwise thread and input plugin CoreAudio thread.
class IOBufferQueue 
{
public:
	IOBufferQueue();
	virtual ~IOBufferQueue();
	
public:
	bool AllocateAll(AkUInt16 sampleSize);
	bool DeAllocateAll();
	bool IsAllocated();
	
	AkUInt16 ReadFromProducer(const AkOSChar* inBuffer, AkUInt16 requestByteSize);
	AkUInt16 WriteToConsumer(AkOSChar* outBuffer, AkUInt16 requestByteSize);
	bool IsOverrun() const;
	bool IsUnderrun() const;
	void ResetOverrun();
	void ResetUnderrun();
	
private:
	enum BufferStatus
	{
		ReadyForProducer,
		ReadyForConsumer,
		NotAllocated
	};
	
private:
	void GoToNextProducerBuffer();
	void GoToNextConsumerBuffer();
	
private:
	AkOSChar* m_buffers[AK_IO_BUFFER_COUNT];
	BufferStatus m_bufferStatus[AK_IO_BUFFER_COUNT];
	AkUInt16 m_bufferByteSize;
	AkUInt16 m_currentConsumeStartPos;
	AkUInt16 m_producerBufferIndex;	
	AkUInt16 m_consumerBufferIndex;	
	bool m_isOverrun;
	bool m_isUnderrun;
	
	CAkLock m_lock;
};


#endif
