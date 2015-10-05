#include "apue.h"

static void sig_alrm(int signo)
{
	/*do nothing, just returning wakes up sigsupend()*/
}

/*old sleep*/
unsigned int sleep1(unsigned int nsecs)
{
	if(signal(SIGALRM, sig_alrm) == SIG_ERR)
		return (nsecs);
	alarm(nsecs);
	pause();
	return (alarm(0));
}

unsigned int sleep(unsigned int nsecs)
{
	struct sigaction newact, oldact;
	sigset_t newmask, oldmask, suspmask;
	unsigned int unslept;

	/*保存旧的信号集合*/
	newact.sa_handler = sig_alrm;
	sigemptyset(&newact.sa_mask);
	newact.sa_flags = 0;
	sigaction(SIGALRM, &newact, &oldact);


	/*屏蔽SIGALRM信号字，同时保存以前的信号屏蔽字*/
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGALRM);
	sigprocmask(SIG_BLOCK, &newmask, &oldmask);
	
	alarm(nsecs); /*nsecs秒钟之后调用产生alarm信号*/

	suspmask = oldmask;
	sigdelset(&suspmask, SIGALRM); /*确保alarm不被屏蔽*/
	sigusupend(&suspmask); /*确保接收所有数据 */

	/*some signal has been caught, SIGALRM is now blocked*/

	unslept = alarm(0);
	sigaction(SIGALRM, &oldact, NULL); /*重置旧的信号动作*/
	
	/*重置信号集合*/
	sigprocmask(SIG_SETMASK, &oldmask, NULL);
	return (unslept);
}
