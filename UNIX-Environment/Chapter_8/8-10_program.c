#include "apue.h"
#include <sys/wait.h>

char path[] = "/home/forest/test/Code_Linux/Chapter_8/testinterp.sh";

int main(void)
{
	pid_t pid;
	if((pid = fork()) < 0)
		err_sys("fork error");
	else if(pid == 0)
	{
		if(execl(path, "testinterp", "myarg1", "MY_ARG2", (char *) 0) < 0)
			err_sys("execl error");
	}
	if(waitpid(pid, NULL, 0) < 0)
		err_sys("waitpid error");
	exit(0);
}
