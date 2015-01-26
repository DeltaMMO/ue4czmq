// Copyright 2015 Palm Stone Games, Inc. All Rights Reserved.

#include "ue4czmq.h"
#include "frame.h"
#include "AllowWindowsPlatformTypes.h"
#include <czmq/czmq.h>
#include "HideWindowsPlatformTypes.h"

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

FZmqFrame::~FZmqFrame()
{
	if (frame != nullptr) zframe_destroy(&frame);
}

bool FZmqFrame::Valid()
{
	return frame != nullptr;
}

bool FZmqFrame::More()
{
	return zframe_more(frame) == 1 ? true : false;
}

uint8* FZmqFrame::GetDataPtr()
{
	return zframe_data(frame);
}

size_t FZmqFrame::GetDataSize()
{
	return zframe_size(frame);
}

TArray<uint8> FZmqFrame::GetData()
{
	TArray<uint8> arr;
	arr.Append(GetDataPtr(), GetDataSize());
	return arr;
}