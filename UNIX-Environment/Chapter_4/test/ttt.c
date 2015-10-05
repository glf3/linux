#include "apue.h"
#include <unistd.h>

int main(int argc, char *argv[])
{
	if(argc != 1)
		err_sys("sys error");
	if(rmdir(argv[1]) < 0)
		err_sys("rmdir error");
	exit(0);
}
