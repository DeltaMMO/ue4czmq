// Copyright 2015 Palm Stone Games, Inc. All Rights Reserved.

#include "ue4czmq.h"
#include "loader.h"
#include "AllowWindowsPlatformTypes.h"
#include <czmq/czmq.h>
#include "HideWindowsPlatformTypes.h"

void ue4czmqImpl::StartupModule()
{
	zsys_init();
}

void ue4czmqImpl::ShutdownModule()
{
	zsys_shutdown();
}

IMPLEMENT_MODULE(ue4czmqImpl, ue4czmq)