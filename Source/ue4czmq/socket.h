#include "ue4czmq.h"
#include "frame.h"

namespace EZmqSocketType
{
	enum Type
	{
		Pair = ZMQ_PAIR,
		Pub = ZMQ_PUB,
		Sub = ZMQ_SUB,
		Req = ZMQ_REQ,
		Rep = ZMQ_REP,
		Dealer = ZMQ_DEALER,
		Router = ZMQ_ROUTER,
		Pull = ZMQ_PULL,
		Push = ZMQ_PUSH,
		xPub = ZMQ_XPUB,
		xSub = ZMQ_XSUB,
		Stream = ZMQ_STREAM,
	};
}

class FZmqSocket
{
public:
	FZmqSocket(EZmqSocketType::Type type);
	~FZmqSocket();
	FZmqSocket(FZmqSocket&) = delete;
	FZmqSocket(FZmqSocket&&) = delete;

	static FZmqSocket* CreatePair(EZmqSocketType::Type type, FString format);
	static FZmqSocket* CreatePub(EZmqSocketType::Type type, FString format);
	static FZmqSocket* CreateSub(EZmqSocketType::Type type, FString format, FString subscribe);
	static FZmqSocket* CreateRep(EZmqSocketType::Type type, FString format);
	static FZmqSocket* CreateReq(EZmqSocketType::Type type, FString format);
	static FZmqSocket* CreateDealer(EZmqSocketType::Type type, FString format);
	static FZmqSocket* CreateRouter(EZmqSocketType::Type type, FString format);
	static FZmqSocket* CreatePull(EZmqSocketType::Type type, FString format);
	static FZmqSocket* CreateXPub(EZmqSocketType::Type type, FString format);
	static FZmqSocket* CreateXSub(EZmqSocketType::Type type, FString format);
	static FZmqSocket* CreateStream(EZmqSocketType::Type type, FString format);

	bool Bind(FString format, int* port = nullptr);
	bool Unbind(FString format);
	bool Connect(FString format);
	bool Disconnect(FString format);
	bool Attach(FString format, bool serverish);

	FZmqFrame RecvFrame(bool wait = true);
	TArray<FZmqFrame> RecvMessage(bool wait = true);
private:
	FZmqSocket(zsock_t* sock);
	zsock_t* sock;
};