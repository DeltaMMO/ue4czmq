// Copyright 2015 Palm Stone Games, Inc. All Rights Reserved.
#pragma once
#include "ue4czmq.h"

// Forward declare the t struct so we can use it here
// Without having to include the whole of czmq, which would severely
// polute our global namespace
typedef struct _zsock_t zsock_t;

class UE4CZMQ_API FZmqSocket
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
	TArray<FZmqFrame> RecvMsg(bool wait = true);
	// Send a frame
	bool SendFrame(FZmqFrame frame);
	// Send a frame
	bool SendMsg(TArray<FZmqFrame> msg);
	bool SendData(const uint8* data, size_t len, bool more = false);
	bool SendData(const char* data, size_t len, bool more = false);
	
	//  Get socket options
	int Tos();
	FString ZapDomain();
	int Mechanism();
	int PlainServer();
	FString PlainUsername();
	FString PlainPassword();
	int CurveServer();
	FString CurvePublickey();
	FString CurveSecretkey();
	FString CurveServerkey();
	int GssapiServer();
	int GssapiPlaintext();
	FString GssapiPrincipal();
	FString GssapiServicePrincipal();
	int Ipv6();
	int Immediate();
	int Ipv4only();
	EZmqSocketType::Type Type();
	int Sndhwm();
	int Rcvhwm();
	int Affinity();
	FString Identity();
	int Rate();
	int RecoveryIvl();
	int Sndbuf();
	int Rcvbuf();
	int Linger();
	int ReconnectIvl();
	int ReconnectIvlMax();
	int Backlog();
	int Maxmsgsize();
	int Multicast_hops();
	int Rcvtimeo();
	int Sndtimeo();
	int TcpKeepalive();
	int TcpKeepaliveIdle();
	int TcpKeepaliveCnt();
	int TcpKeepaliveIntvl();
	FString TcpAcceptFilter();
	int Rcvmore();
	int Fd();
	int Events();
	FString LastEndpoint();

	//  Set socket options
	void SetTos(int tos);
	void SetRouterHandover(int router_handover);
	void SetRouterMandatory(int router_mandatory);
	void SetProbeRouter(int probe_router);
	void SetReqRelaxed(int req_relaxed);
	void SetReqCorrelate(int req_correlate);
	void SetConflate(int conflate);
	void SetZapDomain(FString zap_domain);
	void SetPlainServer(int plain_server);
	void SetPlainUsername(FString plain_username);
	void SetPlainPassword(FString plain_password);
	void SetCurveServer(int curve_server);
	void SetCurvePublickey(FString curve_publickey);
	void SetCurvePublickey(const uint8 *curve_publickey);
	void SetCurveSecretkey(FString curve_secretkey);
	void SetCurveSecretkey(const uint8 *curve_secretkey);
	void SetCurveServerkey(FString curve_serverkey);
	void SetCurveServerkey(const uint8 *curve_serverkey);
	void SetGssapiServer(int gssapi_server);
	void SetGssapiPlaintext(int gssapi_plaintext);
	void SetGssapiPrincipal(FString gssapi_principal);
	void SetGssapiServicePrincipal(FString gssapi_service_principal);
	void SetIpv6(int ipv6);
	void SetImmediate(int immediate);
	void SetRouterRaw(int router_raw);
	void SetIpv4only(int ipv4only);
	void SetDelayAtachOnConnect(int delay_attach_on_connect);
	void SetSndhwm(int sndhwm);
	void SetRcvhwm(int rcvhwm);
	void SetAffinity(int affinity);
	void SetSubscribe(FString subscribe);
	void SetUnsubscribe(FString unsubscribe);
	void SetIdentity(FString identity);
	void SetRate(int rate);
	void SetRecoveryIvl(int recovery_ivl);
	void SetSndbuf(int sndbuf);
	void SetRcvbuf(int rcvbuf);
	void SetLinger(int linger);
	void SetReconnectIvl(int reconnect_ivl);
	void SetReconnectIvlMax(int reconnect_ivl_max);
	void SetBacklog(int backlog);
	void SetMaxmsgsize(int maxmsgsize);
	void SetMulticastHops(int multicast_hops);
	void SetRcvtimeo(int rcvtimeo);
	void SetSndtimeo(int sndtimeo);
	void SetXpubVerbose(int xpub_verbose);
	void SetTcpKeepalive(int tcp_keepalive);
	void SetTcpKeepaliveIdle(int tcp_keepalive_idle);
	void SetTcpKeepaliveCnt(int tcp_keepalive_cnt);
	void SetTcpKeepaliveIntvl(int tcp_keepalive_intvl);
	void SetTcpAcceptFilter(FString tcp_accept_filter);
private:
	FZmqSocket(zsock_t* sock);
	zsock_t* sock;
};