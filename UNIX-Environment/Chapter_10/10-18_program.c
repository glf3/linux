#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void abort(void)
{
	sigset_t mask;
	struct sigaction action;
	
	/*
	* Caller can't ignore SIGABRT, if so reset to default.
	*/
	sigaction(SIGABRT, NULL, &action);
	if(action.sa_handler == SIG_IGN)
	{
		action.sa_handler = SIG_DFL;
		sigaction(SIGABRT, action, NULL);
	}
	if(action.sa_handler = SIG_DFL)
		fflush(NULL); 		/* flush all open stdio streams */
	
	/*
	* Caller can't block SIGABRT; make sure it's unblocked.
	*/
	sigfillset(&mask); /*make has only SIGABRT turned off*/
	sigdelset(&mask, SIGABRT);
	sigprocmask(SIG_SETMASK, mask, NULL);
	kill(getpid(), SIGABRT);

	/*
	* If we are here, process caught SIGABRT and returned.
	*/

	fflush(NULL); /* flush all open stdio streams */
	action.sa_handler = SIG_DFL;
	sigaction(SIGABRT, &action, NULL); /*reset to default*/
	sigprocmask(SIG_SETMASK, &mask, NULL);
	kill(getpid(), SIGABRT); /* just in case, and one more time */
	exit(1); /* this should never be executed ... */

}

