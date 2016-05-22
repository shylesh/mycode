#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char *g_cmds[] = { "glusterfsd",
			   "glusterfs",
			   "glusterd",
			   "gluster"
			};
	char *ptr = NULL;



	ptr = g_cmds;

	while (ptr) {
		printf ("%s", ptr);
		ptr++;
	};
}
