#include "Controller.h"
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
int main()
{
	
	Controller c;
	c.run();
	_CrtDumpMemoryLeaks();
	return 0;
}
