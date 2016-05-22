#include <stdio.h>

#ifdef SYSTEM
#if SYSTEM == linux
	#define HDR "linux"
#elif SYSTEM == windows
	#define HDR "windows"
#elif SYSTEM == solaris
	#define HDR "solaris"
#endif
#endif

int main()
{
	printf ("%s", HDR);
}
	
