#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void sig_handler (int	sign);

int main()
{

	if (signal (SIGINT, sig_handler) == SIG_ERR)
		err_exit ("signal installing failed\n");

	/* give some time */
	sleep (10);


}

void
sig_handler (int sign)
{
	printf ("caught the signal\n");
}
