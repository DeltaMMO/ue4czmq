// Copyright 2015 Palm Stone Games, Inc. All Rights Reserved.

#include "ue4czmq.h"
#ifdef _WIN32
#include "AllowWindowsPlatformTypes.h"
#include <czmq/czmq.h>
#include "HideWindowsPlatformTypes.h"
#else
#include <czmq/czmq.h>
#endif

DEFINE_LOG_CATEGORY(ue4czmq);

class ue4czmqImpl : public FDefaultModuleImpl
{
public:
	void StartupModule();
	void ShutdownModule();
};

void ue4czmqImpl::StartupModule()
{
	UE_LOG(ue4czmq, Log, TEXT("Starting"));
	putenv((char*)"ZSYS_SIGHANDLER=false");
	zsys_init();
}

void ue4czmqImpl::ShutdownModule()
{
	UE_LOG(ue4czmq, Log, TEXT("Shutting down"));
	zsys_shutdown();
}

IMPLEMENT_MODULE(ue4czmqImpl, ue4czmq)