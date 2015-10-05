#include "apue.h"

int main()
{
	pid_t pid;
	if((pid = fork()) < 0)
		err_sys("fork error");
	else if(pid == 0)
	{
		printf("The child process PID is %d.\n", getpid());
		printf("The Group ID is %d.\n", getpgrp());
		printf("The Group ID is %d.\n", getpgid(0));
		printf("The Group ID is %d.\n", getpgid(getpid()));
		exit(0);
	}
}
