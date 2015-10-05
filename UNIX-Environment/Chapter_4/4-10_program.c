#include "apue.h"
#include <sys/types.h>
#include <sys/sysmacros.h> /*In Ubuntu, must include this headfile*/
#ifdef SOLARIS
#include <sys/mkdev.h>
#endif

#ifdef minor
	static int have = 1;
#else
	static int have = 0;
#endif

int main(int argc, char *argv[])
{
	int i;
	struct stat buf;
	printf("have minor?: %d\n", have);
	for(i = 1; i < argc; i++)
	{
		printf("%s: ", argv[i]);
		if(stat(argv[i], &buf) < 0)
		{
			err_ret("stat error");
			continue ;
		}

		printf("dev = %d/%d", major(buf.st_dev), minor(buf.st_dev));
		if(S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
		{
			printf("(%s): rdev = %d/%d", S_ISCHR(buf.st_mode)? "CHARTER": "BLOCK", major(buf.st_rdev), minor(buf.st_rdev));
		}
		printf("\n");
	}
	exit(0);
}
