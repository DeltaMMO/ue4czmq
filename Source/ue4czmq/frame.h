#include "ue4czmq.h"

class FZmqFrame
{
	template<typename byte, typename FDefaultAllocator>
	friend class TArray;

public:
	FZmqFrame(zframe_t* frame);
	~FZmqFrame();
	FZmqFrame(FZmqFrame&&);

	// Returns true if this frame is valid
	bool Valid();

	// Returns true if more frames follow after this one within the same message
	bool More();

	// Returns a copy of the data in the frame, stored inside a TArray<byte>
	TArray<byte> GetData();

	// Returns a pointer to the data in the frame, this pointer is only valid for the lifetime of the frame
	byte* GetDataPtr();

	// Returns the amount of data
	size_t GetDataSize();
private:
	FZmqFrame(const FZmqFrame&);
	zframe_t* frame;
};