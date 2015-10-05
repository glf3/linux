#include "apue.h"

Sigfunc *signal(int signo, Sigfunc *func)
{
	struct sigaction act, oact;

	act.sa_handler = func;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	if(signo == SIGALRM)
	{
		#ifdef SA_INTERRUPt
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
	return (oact.sa_handler);
}

static void sig_quit(int signo)
{
	printf("caught SIGQUIT\n");
	if(signal(SIGQUIT, SIG_DFL) == SIG_ERR)
		err_sys("can't reset SIGQUIT");
}

int main(void)
{
	sigset_t newmask, oldmask, pendmask;

	if(signal(SIGQUIT, sig_quit) == SIG_ERR)
		err_sys("can't catch SIGQUIT");
	
	/*
	*  Block SIGQUIT and save current signal mask.
	*/

	sigemptyset(&newmask);
	sigaddset(&newmask, SIGQUIT);
	if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
		err_sys("SIG_BLOCK error");
	
	sleep(5);

	if(sigpending(&pendmask) < 0)
		err_sys("sigpending error");
	if(sigismember(&pendmask, SIGQUIT))
		printf("\nSIGQUIT pending\n");
	
	/*
	* Reset signal mask which unblocks SIGQUIT.
	*/

	if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		err_sys("SIG_SETMASK error");
	printf("SIGQUIT unblocked\n");

	sleep(5); /* SIGQUIT here will terminate with core file */
	exit(0);
}
