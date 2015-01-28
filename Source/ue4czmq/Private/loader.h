// Copyright 2015 Palm Stone Games, Inc. All Rights Reserved.

#pragma once
#include "ue4czmq.h"

class ue4czmqImpl : public FDefaultModuleImpl
{
public:
	/** IModuleInterface implementation */
	void StartupModule();
	void ShutdownModule();
};