#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <limits.h>
#include <errno.h>
#include <string.h>

static volatile sig_atomic_t	hit = 0;
char				config_file[PATH_MAX] = "./config";
char				log_file[PATH_MAX] = "./d.log";
FILE				*config_fp, *log_fp;

void
handler (int signum)
{
	hit = 1;
}

int
read_config()
{

	char	*ret;
	char	buf[100] = {0};
	char	err[1024] ;

	errno = 0;
	rewind(config_fp);
	ret = fgets (buf, 100, config_fp);
	if (!ret) {
		strcpy (err,  strerror(errno) );
		write_log (err);
	}
	/* print in the log */
	else
		write_log (buf);

	return;
}

int
write_log(char *str)
{

	int	ret;
	char	local_str[1024];

	snprintf (local_str, 1024, "[%s %s]:%s",__DATE__,  __TIME__, str);

	ret = fputs (local_str, log_fp);
	if (feof(log_fp))
		exit(1);
	if (ferror(log_fp))
		exit(2);
	fflush (log_fp);

	return;
}

int
daemonize()
{
	/* daemonize should do fork and close
 	* close all the associated 0, 1 & 2 fds
 	*/

	pid_t	pid;

	pid = fork();

	switch (pid) {
	case  -1:	write_log("fork error\n");
	case 0:		break;
	default:	sleep(10);
			write_log ("parent exiting\n");
			wait(NULL);
			exit(0);
	}

	pid = fork();

	switch (pid) {
	case -1:	write_log ("fork failed\n");
	case 0:		break;
	default:	write_log ("child 1exiting\n");
			exit(0);
	}

	close(0);
	close(1);
	close(2);
	write_log ("starting worker\n");

	return;

}

int
main()
{
	struct sigaction	sigact;
	int			ret;
	sigset_t		sigs;
	char			err[1024] = {0};

	sigemptyset (&sigs);
	sigaddset (&sigs, SIGHUP);

	sigact.sa_handler = handler;
	sigact.sa_mask = sigs;
	sigact.sa_flags = SA_RESTART;

	ret = sigaction (SIGHUP,&sigact, NULL);

	config_fp = fopen(config_file, "r");
	if (!config_fp) {
		snprintf (err, 1024, "%s : %s", "failed to open config file", strerror (errno));
		write_log (err);
	}
	setbuf (config_fp, NULL);

	log_fp = fopen (log_file, "a+");
	if (!log_fp)
		err_exit ("failed to open log file\n");

	setbuf (log_fp, NULL);

	read_config();
	write_log("from main");
	daemonize();
	siginterrupt (SIGHUP, 0);

	while (1) {
		if (!hit)
			pause();

		hit = 0;
		write_log ("recieved sighup\n");
		read_config();

	}
}
