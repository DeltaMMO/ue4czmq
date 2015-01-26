#include "ue4czmq.h"

// Forward declare the zframe_t struct so we can use it here
// Without having to include the whole of czmq, which would severely
// polute our global namespace
typedef struct _zframe_t zframe_t;

class FZmqFrame
{
	template<typename byte, typename FDefaultAllocator>
	friend class TArray;
	friend class FZmqSocket;

public:
	~FZmqFrame();
	FZmqFrame(FZmqFrame&&);

	// Returns true if this frame is valid
	bool Valid();

	// Returns true if more frames follow after this one within the same message
	bool More();

	// Returns a copy of the data in the frame, stored inside a TArray<byte>
	TArray<uint8> GetData();

	// Returns a pointer to the data in the frame, this pointer is only valid for the lifetime of the frame
	uint8* GetDataPtr();

	// Returns the amount of data
	size_t GetDataSize();
private:
	FZmqFrame(zframe_t* frame);
	FZmqFrame(const FZmqFrame&);
	zframe_t* frame;
};