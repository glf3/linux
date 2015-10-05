#include "apue.h"
#include "unistd.h"
#include "sys/wait.h"
#include "sys/types.h"
#include "fcntl.h"

int main()
{
	pid_t pid;
	int i, fd;
	char *buf = "This is a daemon program.\n";
	if((pid = fork()) < 0)
		err_sys("fork error");
	else if(pid > 0)
		exit(0);
	else if(pid == 0)
	{
		setsid();
		chdir("/");
		umask(0);
		for(i = 0; i < getdtablesize(); i++)
			close(i);
		for(;;)
		{
			if((fd = open("/tmp/daemon.log", O_CREAT|O_WRONLY|O_APPEND,0600)) < 0)
				err_sys("Open file error!");
			write(fd, buf, strlen(buf)+1);
			close(fd);
			sleep(10);
			printf("Never output!\n");
		}
	}
	return 0;
}
