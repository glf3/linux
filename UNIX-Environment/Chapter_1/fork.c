#include "apue.h"
#include <sys/wait.h>

int main()
{
	char buf[MAXLINE];
	pid_t pid;
	int status;

	printf("%% ");
	printf("curentpid: %d\n", getpid());
	while(fgets(buf, MAXLINE, stdin) != NULL)
	{
		printf("curpid: %d\n", getpid());
		if(buf[strlen(buf)-1] == '\n')
			buf[strlen(buf)-1] = 0;
		if((pid = fork()) < 0)
		{
			err_sys("fork error\n");
		}
		else if(pid == 0)
		{
			printf("child_pid: %d\n", getpid());
			printf("parent_pid: %d\n", getppid());
			execlp(buf, buf, (char *)0);
			err_ret("could'nt execute :%s", buf);
			exit(127);
		}
		else
		{
			printf("child_pid1: %d\n", pid);
			if((pid = waitpid(pid, &status, 0)))
			{
				printf("pid: %d\n", pid);
			}
			if(pid < 0)
			{
				err_sys("waitpid error");
			}
			printf("child_pid2:\n", getpid());
			printf("%% ");
		}
	}
	exit(0);
}
