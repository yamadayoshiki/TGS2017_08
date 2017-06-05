#include "Source/Base/GameFrame/GameFrame.h"

#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>

#include <crtdbg.h>

int main() {
	_CrtDumpMemoryLeaks();
	//_CrtSetBreakAlloc(2711);
	return GameFrame().run();
}