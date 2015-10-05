#include "apue.h"

int main()
{
	pid_t pid;
	if((pid = fork()) < 0)
		err_sys("fork error");
	else if(pid == 0)
	{
		printf("The child process PID is %d.\n", getpid());
		printf("The Group ID of child si %d.\n", getpgrp());
		sleep(5);
		printf("The Group ID of child is changed to %d.\n", getpgrp());
		exit(0);
	}

	sleep(1);
	setpgid(pid, pid);
	
	sleep(5);
	printf("The parent process PID is %d.\n", getpid());
	printf("The parent of parent process PID is %d.\n", getppid());
	printf("The Group ID of parent is %d.\n", getpgrp());
	setpgid(getpid(), getppid());
	printf("The Group ID of parent is changed to %d.\n", getpgrp());
	exit(0);
}
