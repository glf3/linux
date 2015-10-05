#include "apue.h"
#include <sys/wait.h>

#define size 4096

static void sig_int(int signo)
{
	printf("interrupt\n");
}

int main(void)
{
	int n;
	char buf[size];
	
	if(signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("signal error");
	
	while((n = read(STDIN_FILENO, buf, size)) > 0)
		if(write(STDOUT_FILENO, buf, n) != n)
			err_sys("write error");
	if(n < 0)
		err_sys("read error");
	exit(0);
}
