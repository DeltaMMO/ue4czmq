// Copyright 2015 Palm Stone Games, Inc. All Rights Reserved.
#pragma once
#include "ue4czmq.h"

// Forward declare the zframe_t struct so we can use it here
// Without having to include the whole of czmq, which would severely
// polute our global namespace
typedef struct _zframe_t zframe_t;

class UE4CZMQ_API FZmqFrame
{
	template<typename byte, typename FDefaultAllocator>
	friend class TArray;
	friend class FZmqSocket;

public:
	// Create a new frame with the passed data. The data will be copied.
	FZmqFrame(uint8* dataPtr, size_t dataSize, bool more = false);
	// Create a new frame with the passed data. The data will be copied.
	FZmqFrame(TArray<uint8> data, bool more = false);
	~FZmqFrame();
	FZmqFrame(FZmqFrame&&);

	// Returns true if this frame is valid
	bool Valid();

	// Returns true if more frames follow after this one within the same message
	bool More();
	// Set the more flag
	void SetMore(bool);

	// Returns a copy of the data in the frame, stored inside a TArray<byte>
	TArray<uint8> GetData();

	// Returns a pointer to the data in the frame, this pointer is only valid for the lifetime of the frame
	uint8* GetDataPtr();

	// Returns the amount of data
	size_t GetDataSize();
private:
	FZmqFrame(zframe_t* frame);
	FZmqFrame(const FZmqFrame&);
	zframe_t* frame;
};