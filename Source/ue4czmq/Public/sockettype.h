#pragma once
#include "ue4czmq.h"
#include "sockettype.generated.h"

UENUM()
namespace EZmqSocketType
{
	enum Type
	{
		Pair = 0,
		Pub = 1,
		Sub = 2,
		Req = 3,
		Rep = 4,
		Dealer = 5,
		Router = 6,
		Pull = 7,
		Push = 8,
		xPub = 9,
		xSub = 10,
		Stream = 11,
	};
}