#include "apue.h"

static void sig_int(int signo)
{
	printf("caught SIGINT\n");
}

static void sig_chld(int signo)
{
	printf("caught SIGCHLD\n");
}

int system(const char *cmdstring) /*versio without signal handling*/
{
	pid_t pid;
	int status;
	if(cmdstring == NULL)
		return 1;
	if((pid = fork()) < 0)
		status = -1;
	else if(pid == 0)
	{
		execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
		_exit(127);
	}
	else
	{
		while(waitpid(pid, &status, 0) < 0)
		{
			if(errno != EINTR)
			{
				status = -1;
				break;
			}
		}
	}
	return status;
}

int main(void)
{
	if(signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("signal(SIGINT) error");
	if(signal(SIGCHLD, sig_chld) == SIG_ERR)
		err_sys("signal(sig_chld) error");
	if(system("/bin/ed") < 0)
		err_sys("system() error");
	exit(0);
}

