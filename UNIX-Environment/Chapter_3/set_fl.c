#include "apue.h"
#include <fcntl.h>

void set_fl(int fd, int flag)
{
	int val;
	if((val = fcntl(fd, F_GETFL, 0)) < 0)
		err_sys("fcntl F_GETFL error");
	val |= flag;

	if(fcntl(fd, F_SETFL, flag) < 0)
		err_sys("fcntl F_SETFL error");
}

int main(void)
{
	set_fl(STDOUT_FILENO, O_SYNC);
	return 0;
}
