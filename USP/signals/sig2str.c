#include <signal.h>
#include <stdlib.h>

//extern char *sys_siglist[];

int
main()
{

	printf ("SIG%s\n", sys_siglist[2]);
}
