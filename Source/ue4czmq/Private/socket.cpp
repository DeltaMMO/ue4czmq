// Copyright 2015 Palm Stone Games, Inc. All Rights Reserved.

#include "ue4czmq.h"
#include "socket.h"
#include "AllowWindowsPlatformTypes.h"
#include <czmq/czmq.h>
#include "HideWindowsPlatformTypes.h"

FZmqSocket::FZmqSocket(EZmqSocketType::Type type)
	: FZmqSocket(zsock_new((int)type))
{
}

FZmqSocket::FZmqSocket(zsock_t* sock)
	: sock(sock)
{
}

FZmqSocket* FZmqSocket::CreatePair(EZmqSocketType::Type type, FString format)
{
	zsock_t* sock = zsock_new_pair(TCHAR_TO_UTF8(*format));
	if (sock == nullptr) return nullptr;
	return new FZmqSocket(sock);
}

FZmqSocket* FZmqSocket::CreatePub(EZmqSocketType::Type type, FString format)
{
	zsock_t* sock = zsock_new_pub(TCHAR_TO_UTF8(*format));
	if (sock == nullptr) return nullptr;
	return new FZmqSocket(sock);
}

FZmqSocket* FZmqSocket::CreateSub(EZmqSocketType::Type type, FString format, FString subscribe)
{
	zsock_t* sock = zsock_new_sub(TCHAR_TO_UTF8(*format), TCHAR_TO_UTF8(*subscribe));
	if (sock == nullptr) return nullptr;
	return new FZmqSocket(sock);
}

FZmqSocket* FZmqSocket::CreateRep(EZmqSocketType::Type type, FString format)
{
	zsock_t* sock = zsock_new_rep(TCHAR_TO_UTF8(*format));
	if (sock == nullptr) return nullptr;
	return new FZmqSocket(sock);
}

FZmqSocket* FZmqSocket::CreateReq(EZmqSocketType::Type type, FString format)
{
	zsock_t* sock = zsock_new_req(TCHAR_TO_UTF8(*format));
	if (sock == nullptr) return nullptr;
	return new FZmqSocket(sock);
}

FZmqSocket* FZmqSocket::CreateDealer(EZmqSocketType::Type type, FString format)
{
	zsock_t* sock = zsock_new_dealer(TCHAR_TO_UTF8(*format));
	if (sock == nullptr) return nullptr;
	return new FZmqSocket(sock);
}

FZmqSocket* FZmqSocket::CreateRouter(EZmqSocketType::Type type, FString format)
{
	zsock_t* sock = zsock_new_router(TCHAR_TO_UTF8(*format));
	if (sock == nullptr) return nullptr;
	return new FZmqSocket(sock);
}

FZmqSocket* FZmqSocket::CreatePull(EZmqSocketType::Type type, FString format)
{
	zsock_t* sock = zsock_new_pull(TCHAR_TO_UTF8(*format));
	if (sock == nullptr) return nullptr;
	return new FZmqSocket(sock);
}

FZmqSocket* FZmqSocket::CreateXPub(EZmqSocketType::Type type, FString format)
{
	zsock_t* sock = zsock_new_xpub(TCHAR_TO_UTF8(*format));
	if (sock == nullptr) return nullptr;
	return new FZmqSocket(sock);
}

FZmqSocket* FZmqSocket::CreateXSub(EZmqSocketType::Type type, FString format)
{
	zsock_t* sock = zsock_new_xsub(TCHAR_TO_UTF8(*format));
	if (sock == nullptr) return nullptr;
	return new FZmqSocket(sock);
}

FZmqSocket* FZmqSocket::CreateStream(EZmqSocketType::Type type, FString format)
{
	zsock_t* sock = zsock_new_stream(TCHAR_TO_UTF8(*format));
	if (sock == nullptr) return nullptr;
	return new FZmqSocket(sock);
}

FZmqSocket::~FZmqSocket()
{
	zsock_destroy(&sock);
}

bool FZmqSocket::Bind(FString format, int* port)
{
	int p = zsock_bind(sock, TCHAR_TO_UTF8(*format));
	if(p == -1) return false;

	if (port != NULL) *port = p;
	return true;
}

bool FZmqSocket::Unbind(FString format)
{
	int rc = zsock_unbind(sock, TCHAR_TO_UTF8(*format));
	return rc != -1;
}

bool FZmqSocket::Connect(FString format)
{
	int rc = zsock_connect(sock, TCHAR_TO_UTF8(*format));
	return rc != -1;
}

bool FZmqSocket::Disconnect(FString format)
{
	int rc = zsock_disconnect(sock, TCHAR_TO_UTF8(*format));
	return rc != -1;
}

bool FZmqSocket::Attach(FString format, bool serverish)
{
	int rc = zsock_attach(sock, TCHAR_TO_UTF8(*format), serverish);
	return rc != -1;
}

FZmqFrame FZmqSocket::RecvFrame(bool wait)
{
	zframe_t* frame;
	if (wait) frame = zframe_recv(this->sock);
	else frame = zframe_recv_nowait(this->sock);

	return FZmqFrame(frame);
}

TArray<FZmqFrame> FZmqSocket::RecvMessage(bool wait)
{
	TArray<FZmqFrame> frames;
	FZmqFrame f(nullptr);

	do
	{
		f = RecvFrame(wait);
		if (f.Valid()) frames.Add(f);
	} while (f.Valid() && f.More());

	return frames;
}