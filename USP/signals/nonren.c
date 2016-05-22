#define _XOPEN_SOURCE

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handler (int signum );

char	*str2;
int	handled;

void
handler (int signum)
{
	crypt (str2, "xx");
	handled++;
}

int
main (int argc, char *argv[])
{
	char		*cr1;
	int			attempt, miss;
	struct sigaction 	act;

	cr1 = strdup(crypt(argv[1], "xx"));
	str2 = argv[2];

	/* install the handler */
	act.sa_handler = handler;
	sigemptyset (&act.sa_mask);
	act.sa_flags = 0;
	sigaction (SIGINT, &act, NULL);

	/* repeatedly call crypt */
	for (attempt =  0, miss = 0; ; attempt++)
		if (strcmp(cr1, crypt(argv[1], "xx")) != 0)
			printf ("mismatch\n");

}
