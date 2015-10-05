#include "apue.h"

#define SIZE 1024

static void sig_tstp(int);

int main(void)
{
	int n;
	char buf[SIZE];

	/*
	* Only catch SIGTSTP if we're running with a job-control shell.
	*/
	if(signal(SIGTSTP, SIG_IGN) == SIG_DFL)
		signal(SIGTSTP, sig_tstp);
	
	while((n = read(STDIN_FILENO, buf, SIZE)) > 0)
		if(write(STDOUT_FILE, buf, n) != n)
			err_sys("write error");
	if(n < 0)
		err_sys("read error");
	exit(0);
}

static void sig_tstp(int signo)
{
	sigset_t mask;
	/*
	* move curson to lower left corner, reset tty mode ...
	*/

	/*
	*Unblock SIGTSTP, since it's blocked while we're handling it.
	*/
	
	sigemptyset(&mask);
	sigaddset(&mask, SIGTSTP);
	sigprocmask(SIG_UNBLOCK, &mask, NULL);

	kill(getpid(), SIGTSTP);

	/*
	* we won't return from the kill until we're continued.
	*/

	signal(SIGTSTP, sig_tstp); /*restablish signal handler*/
	
	/*reset tty mode, redraw screen...*/
}


