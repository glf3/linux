/*
print what you write from STDIN...
*/
#include "apue.h"

const int maxsize = 1024;

int main(void)
{
	char buf[maxsize];

	while(fgets(buf, maxsize, stdin) != NULL)
		if(fputs(buf, stdout) == EOF)
			err_sys("output error");
	if(ferror(stdin))
		err_sys("input error");
	exit(0);
}
