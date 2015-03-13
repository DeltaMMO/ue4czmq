// Copyright 2015 Palm Stone Games, Inc. All Rights Reserved.

#include "ue4czmq.h"
#include "socket.h"
#ifdef _WIN32
#include "AllowWindowsPlatformTypes.h"
#include <czmq/czmq.h>
#include "HideWindowsPlatformTypes.h"
#else
#include <czmq/czmq.h>
#endif
int FZmqSocket::Tos() const
{
	return zsock_tos(sock);
}

FString FZmqSocket::ZapDomain() const
{
	return FString(zsock_zap_domain(sock));
}

int FZmqSocket::Mechanism() const
{
	return zsock_mechanism(sock);
}

int FZmqSocket::PlainServer() const
{
	return zsock_plain_server(sock);
}

FString FZmqSocket::PlainUsername() const
{
	return FString(zsock_plain_username(sock));
}

FString FZmqSocket::PlainPassword() const
{
	return FString(zsock_plain_password(sock));
}

int FZmqSocket::CurveServer() const
{
	return zsock_curve_server(sock);
}

FString FZmqSocket::CurvePublickey() const
{
	return FString(zsock_curve_publickey(sock));
}

FString FZmqSocket::CurveSecretkey() const
{
	return zsock_curve_secretkey(sock);
}

FString FZmqSocket::CurveServerkey() const
{
	return zsock_curve_serverkey(sock);
}

int FZmqSocket::GssapiServer() const
{
	return zsock_gssapi_server(sock);
}

int FZmqSocket::GssapiPlaintext() const
{
	return zsock_gssapi_plaintext(sock);
}

FString FZmqSocket::GssapiPrincipal() const
{
	return zsock_gssapi_principal(sock);
}

FString FZmqSocket::GssapiServicePrincipal() const
{
	return zsock_gssapi_service_principal(sock);
}

int FZmqSocket::Ipv6() const
{
	return zsock_ipv6(sock);
}

int FZmqSocket::Immediate() const
{
	return zsock_immediate(sock);
}

int FZmqSocket::Ipv4only() const
{
	return zsock_ipv4only(sock);
}

EZmqSocketType::Type FZmqSocket::Type() const
{
	return (EZmqSocketType::Type) zsock_type(sock);
}

int FZmqSocket::Sndhwm() const
{
	return zsock_sndhwm(sock);
}

int FZmqSocket::Rcvhwm() const
{
	return zsock_rcvhwm(sock);
}

int FZmqSocket::Affinity() const
{
	return zsock_affinity(sock);
}

FString FZmqSocket::Identity() const
{
	return FString(zsock_identity(sock));
}

int FZmqSocket::Rate() const
{
	return zsock_rate(sock);
}

int FZmqSocket::RecoveryIvl() const
{
	return zsock_recovery_ivl(sock);
}

int FZmqSocket::Sndbuf() const
{
	return zsock_sndbuf(sock);
}

int FZmqSocket::Rcvbuf() const
{
	return zsock_rcvbuf(sock);
}

int FZmqSocket::Linger() const
{
	return zsock_linger(sock);
}

int FZmqSocket::ReconnectIvl() const
{
	return zsock_reconnect_ivl(sock);
}

int FZmqSocket::ReconnectIvlMax() const
{
	return zsock_reconnect_ivl_max(sock);
}

int FZmqSocket::Backlog() const
{
	return zsock_backlog(sock);
}

int FZmqSocket::Maxmsgsize() const
{
	return zsock_maxmsgsize(sock);
}

int FZmqSocket::Multicast_hops() const
{
	return zsock_multicast_hops(sock);
}

int FZmqSocket::Rcvtimeo() const
{
	return zsock_rcvtimeo(sock);
}

int FZmqSocket::Sndtimeo() const
{
	return zsock_sndtimeo(sock);
}

int FZmqSocket::TcpKeepalive() const
{
	return zsock_tcp_keepalive(sock);
}

int FZmqSocket::TcpKeepaliveIdle() const
{
	return zsock_tcp_keepalive_idle(sock);
}

int FZmqSocket::TcpKeepaliveCnt() const
{
	return zsock_tcp_keepalive_cnt(sock);
}

int FZmqSocket::TcpKeepaliveIntvl() const
{
	return zsock_tcp_keepalive_intvl(sock);
}

FString FZmqSocket::TcpAcceptFilter() const
{
	return FString(zsock_tcp_accept_filter(sock));
}

int FZmqSocket::Rcvmore() const
{
	return zsock_rcvmore(sock);
}

int FZmqSocket::Fd() const
{
	return zsock_fd(sock);
}

int FZmqSocket::Events() const
{
	return zsock_events(sock);
}

FString FZmqSocket::LastEndpoint() const
{
	return FString(zsock_last_endpoint(sock));
}

void FZmqSocket::SetTos(int tos)
{
	zsock_set_tos(sock, tos);
}

void FZmqSocket::SetRouterHandover(int router_handover)
{
	zsock_set_router_handover(sock, router_handover);
}

void FZmqSocket::SetRouterMandatory(int router_mandatory)
{
	zsock_set_router_mandatory(sock, router_mandatory);
}

void FZmqSocket::SetProbeRouter(int probe_router)
{
	zsock_set_probe_router(sock, probe_router);
}

void FZmqSocket::SetReqRelaxed(int req_relaxed)
{
	zsock_set_req_relaxed(sock, req_relaxed);
}

void FZmqSocket::SetReqCorrelate(int req_correlate)
{
	zsock_set_req_correlate(sock, req_correlate);
}

void FZmqSocket::SetConflate(int conflate)
{
	zsock_set_conflate(sock, conflate);
}

void FZmqSocket::SetZapDomain(FString zap_domain)
{
	zsock_set_zap_domain(sock, TCHAR_TO_UTF8(*zap_domain));
}

void FZmqSocket::SetPlainServer(int plain_server)
{
	zsock_set_plain_server(sock, plain_server);
}

void FZmqSocket::SetPlainUsername(FString plain_username)
{
	zsock_set_plain_username(sock, TCHAR_TO_UTF8(*plain_username));
}

void FZmqSocket::SetPlainPassword(FString plain_password)
{
	zsock_set_plain_password(sock, TCHAR_TO_UTF8(*plain_password));
}

void FZmqSocket::SetCurveServer(int curve_server)
{
	zsock_set_curve_server(sock, curve_server);
}

void FZmqSocket::SetCurvePublickey(FString curve_publickey)
{
	zsock_set_curve_publickey(sock, TCHAR_TO_UTF8(*curve_publickey));
}

void FZmqSocket::SetCurvePublickey(const uint8 *curve_publickey)
{
	zsock_set_curve_publickey_bin(sock, curve_publickey);
}

void FZmqSocket::SetCurveSecretkey(FString curve_secretkey)
{
	zsock_set_curve_secretkey(sock, TCHAR_TO_UTF8(*curve_secretkey));
}

void FZmqSocket::SetCurveSecretkey(const uint8 *curve_secretkey)
{
	zsock_set_curve_secretkey_bin(sock, curve_secretkey);
}

void FZmqSocket::SetCurveServerkey(FString curve_serverkey)
{
	zsock_set_curve_serverkey(sock, TCHAR_TO_UTF8(*curve_serverkey));
}

void FZmqSocket::SetCurveServerkey(const uint8 *curve_serverkey)
{
	return zsock_set_curve_serverkey_bin(sock, curve_serverkey);
}

void FZmqSocket::SetGssapiServer(int gssapi_server)
{
	return zsock_set_gssapi_server(sock, gssapi_server);
}

void FZmqSocket::SetGssapiPlaintext(int gssapi_plaintext)
{
	return zsock_set_gssapi_plaintext(sock, gssapi_plaintext);
}

void FZmqSocket::SetGssapiPrincipal(FString gssapi_principal)
{
	return zsock_set_gssapi_principal(sock, TCHAR_TO_UTF8(*gssapi_principal));
}

void FZmqSocket::SetGssapiServicePrincipal(FString gssapi_service_principal)
{
	return zsock_set_gssapi_service_principal(sock, TCHAR_TO_UTF8(*gssapi_service_principal));
}

void FZmqSocket::SetIpv6(int ipv6)
{
	return zsock_set_ipv6(sock, ipv6);
}

void FZmqSocket::SetImmediate(int immediate)
{
	return zsock_set_immediate(sock, immediate);
}

void FZmqSocket::SetRouterRaw(int router_raw)
{
	return zsock_set_router_raw(sock, router_raw);
}

void FZmqSocket::SetIpv4only(int ipv4only)
{
	return zsock_set_ipv4only(sock, ipv4only);
}

void FZmqSocket::SetDelayAtachOnConnect(int delay_attach_on_connect)
{
	return zsock_set_delay_attach_on_connect(sock, delay_attach_on_connect);
}

void FZmqSocket::SetSndhwm(int sndhwm)
{
	return zsock_set_sndhwm(sock, sndhwm);
}

void FZmqSocket::SetRcvhwm(int rcvhwm)
{
	return zsock_set_rcvhwm(sock, rcvhwm);
}

void FZmqSocket::SetAffinity(int affinity)
{
	return zsock_set_affinity(sock, affinity);
}

void FZmqSocket::SetSubscribe(FString subscribe)
{
	zsock_set_subscribe(sock, TCHAR_TO_UTF8(*subscribe));
}

void FZmqSocket::SetUnsubscribe(FString unsubscribe)
{
	return zsock_set_unsubscribe(sock, TCHAR_TO_UTF8(*unsubscribe));
}

void FZmqSocket::SetIdentity(FString identity)
{
	return zsock_set_identity(sock, TCHAR_TO_UTF8(*identity));
}

void FZmqSocket::SetRate(int rate)
{
	return zsock_set_rate(sock, rate);
}

void FZmqSocket::SetRecoveryIvl(int recovery_ivl)
{
	return zsock_set_recovery_ivl(sock, recovery_ivl);
}

void FZmqSocket::SetSndbuf(int sndbuf)
{
	return zsock_set_sndbuf(sock, sndbuf);
}

void FZmqSocket::SetRcvbuf(int rcvbuf)
{
	return zsock_set_rcvbuf(sock, rcvbuf);
}

void FZmqSocket::SetLinger(int linger)
{
	return zsock_set_linger(sock, linger);
}

void FZmqSocket::SetReconnectIvl(int reconnect_ivl)
{
	return zsock_set_reconnect_ivl(sock, reconnect_ivl);
}

void FZmqSocket::SetReconnectIvlMax(int reconnect_ivl_max)
{
	return zsock_set_reconnect_ivl_max(sock, reconnect_ivl_max);
}

void FZmqSocket::SetBacklog(int backlog)
{
	return zsock_set_backlog(sock, backlog);
}

void FZmqSocket::SetMaxmsgsize(int maxmsgsize)
{
	return zsock_set_maxmsgsize(sock, maxmsgsize);
}

void FZmqSocket::SetMulticastHops(int multicast_hops)
{
	return zsock_set_multicast_hops(sock, multicast_hops);
}

void FZmqSocket::SetRcvtimeo(int rcvtimeo)
{
	zsock_set_rcvtimeo(sock, rcvtimeo);
}

void FZmqSocket::SetSndtimeo(int sndtimeo)
{
	zsock_set_sndtimeo(sock, sndtimeo);
}

void FZmqSocket::SetXpubVerbose(int xpub_verbose)
{
	zsock_set_xpub_verbose(sock, xpub_verbose);
}

void FZmqSocket::SetTcpKeepalive(int tcp_keepalive)
{
	zsock_set_tcp_keepalive(sock, tcp_keepalive);
}

void FZmqSocket::SetTcpKeepaliveIdle(int tcp_keepalive_idle)
{
	zsock_set_tcp_keepalive_idle(sock, tcp_keepalive_idle);
}

void FZmqSocket::SetTcpKeepaliveCnt(int tcp_keepalive_cnt)
{
	zsock_set_tcp_keepalive_cnt(sock, tcp_keepalive_cnt);
}

void FZmqSocket::SetTcpKeepaliveIntvl(int tcp_keepalive_intvl)
{
	zsock_set_tcp_keepalive_intvl(sock, tcp_keepalive_intvl);
}

void FZmqSocket::SetTcpAcceptFilter(FString tcp_accept_filter)
{
	zsock_set_tcp_accept_filter(sock, TCHAR_TO_UTF8(*tcp_accept_filter));
}
