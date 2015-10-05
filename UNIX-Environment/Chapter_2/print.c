#include "apue.h"

#ifdef _POSIX_THREADS
	static ok = _POSIX_THREADS;
#else
	static ok = 0;
#endif
int main(void)
{
	if(ok == 0)
	{
		int temp = sysconf(_PC_CHOWN_RESTRICTED);
		printf("temp : %d\n", temp);
	}
	else printf("Threads: %d\n", ok);

	return 0;
}
