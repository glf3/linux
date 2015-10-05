#include "apue.h"

volatile sig_atomic_t quitflag;

void pr_mask(const char *str)
{
	sigset_t sigset;
	int errno_save;
	errno_save = errno;
	if(sigprocmask(0, NULL, &sigset) < 0)
		err_sys("sigprocmask error");
	printf("%s", str);
	if(sigismember(&sigset, SIGINT)) printf("SIGINT ");
	if(sigismember(&sigset, SIGQUIT)) printf("SIGQUIT ");
	if(sigismember(&sigset, SIGUSR1)) printf("SIGUSR1 ");
	if(sigismember(&sigset, SIGALRM)) printf("SIGALRM");

	/* remaining signals can go here */
	printf("\n");
	errno = errno_save;
}

Sigfunc *signal(int signo, Sigfunc *func)
{
	struct sigaction act, oact;
	act.sa_handler = func;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	if(signo == SIGALRM)
	{
		#ifdef SA_INTERRUPT
			act.sa_flags |= SA_INTERRUPT;
		#endif
	}
	else
	{
		#ifdef SA_RESTART
			act.sa_flags |= SA_RESTART;
		#endif
	}
	if(sigaction(signo, &act, &oact) < 0)
		return (SIG_ERR);

}
static void sig_int(int signo)
{
	if(signo == SIGINT)
		printf("\nInterrupt\n");
	else if(signo == SIGQUIT)
		quitflag = 1; /* set flag for main loop*/
}

int main(void)
{
	sigset_t newmask, oldmask, zeromask;

	if(signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("signal(SIGINT) error");
	if(signal(SIGQUIT, sig_int) == SIG_ERR)
		err_sys("signal(SIGINT) error");
	
	sigemptyset(&zeromask);
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGQUIT);

	/*
	*	Block SIGQUIT and save current signal mask.
	*/
	
	if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
		err_sys("SIG_BLOCK error");
	
	while(quitflag == 0)
	{
		int r = sigsuspend(&zeromask);
		printf("%d\n", r);
	}
	
	/*
	* 	SIGQUIT has been caught and is now blocked; do whatever;
	*/
	
	pr_mask("Block signal: ");
	quitflag = 0;

	/*
	*	Reset signal mask which unblocks SIGQUIT.
	*/

	if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		err_sys("SIG_SETMASK error");
	sleep(5);
	exit(0);
}
