#include "apue.h"
#include <sys/wait.h>

char *env_init[] = {"USER=unknown", "PATH=/tmp", NULL};

int main(void)
{	
	pid_t pid;
	if((pid = fork()) < 0)
		err_sys("fork error");
	else if(pid == 0)
	{
		if(execle("/home/forest/test/Code_Linux/Chapter_8/echoall", "echoall", "myarg1", "MY_ARG2", (char *)0, env_init) < 0)
		err_sys("execle error");
	}

	if(waitpid(pid, NULL, 0) < 0)
		err_sys("waitpid error");
	if((pid = fork()) < 0)
		err_sys("fork error");
	else if(pid == 0)
	{
		if(execlp("./echoall", "echoall", "myarg1", "MY_ARG2", (char *)0) < 0)
			err_sys("execlp error");
	}
	exit(0);
}
