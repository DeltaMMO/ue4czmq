// Copyright 2015 Palm Stone Games, Inc. All Rights Reserved.

#include "ue4czmq.h"
#include "frame.h"
#ifdef _WIN32
#include "AllowWindowsPlatformTypes.h"
#include <czmq/czmq.h>
#include "HideWindowsPlatformTypes.h"
#else
#include <czmq/czmq.h>
#endif


FZmqFrame::FZmqFrame(const uint8* dataPtr, size_t dataSize, bool more)
	: frame(zframe_new(dataPtr, dataSize))
{
	zframe_set_more(frame, more);
}

FZmqFrame::FZmqFrame(const TArray<uint8> data, bool more)
	: FZmqFrame(data.GetData(), data.Num(), more)
{
}

FZmqFrame::FZmqFrame(zframe_t* frame)
	: frame(frame)
{
}

FZmqFrame::FZmqFrame(const FZmqFrame& other)
	: frame(other.frame)
{
}

FZmqFrame::FZmqFrame(FZmqFrame&& other)
	: frame(other.frame)
{
	other.frame = nullptr;
}

FZmqFrame& FZmqFrame::operator=(FZmqFrame&& other)
{
	frame = other.frame;
	other.frame = nullptr;
	return *this;
}

FZmqFrame::~FZmqFrame()
{
	if (frame != nullptr) zframe_destroy(&frame);
}

bool FZmqFrame::Valid() const
{
	return frame != nullptr;
}

bool FZmqFrame::More() const
{
	return zframe_more(frame) == 1 ? true : false;
}

void FZmqFrame::SetMore(bool more)
{
	zframe_set_more(frame, more);
}

uint8* FZmqFrame::GetDataPtr() const
{
	return zframe_data(frame);
}

size_t FZmqFrame::GetDataSize() const
{
	return zframe_size(frame);
}

TArray<uint8> FZmqFrame::GetData() const
{
	TArray<uint8> arr;
	arr.Append(GetDataPtr(), GetDataSize());
	return arr;
}