#include <signal.h>
#include <errno.h>

#define SIGBAD(signo) ((signo) <= 0 || (signo) >= NSIG)

int sidaddset(sigset_t *set, int signo)
{
	if(SIGBAD(signo)) { errno = ENIVAL; return (-1); }

	*set |= 1 << (signo-1);
}

int sigdelset(sigset_t *set, int signo)
{
	if(SIGBAD(signo)) { errno = EINVAL; return (-1); }

	*set &= ~(1 << (signo-1));
	return (0);
}

int sigismember(const sigset_T *set, int signo)
{
	if(SIGBAD(signo)) { errno = EINVAL; return (-1); }
	return ((*set & (1 << (signo-1))) != 0);
}
