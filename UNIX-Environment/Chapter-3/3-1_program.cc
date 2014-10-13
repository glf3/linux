/*
  Test whether can seek for STDIN_FILENO
*/

#include "apue.h"

int main(void)
{
	if(lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
		printf("can't seek\n");
	else
		printf("seek ok\n");
	exit(0);
}
