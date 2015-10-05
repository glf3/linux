#include "apue.h"
#include <unistd.h>
#include <time.h>

const int maxn = 110;

int main(int argc, char *argv[])
{
	struct stat statbuf;

	struct tm *st_atime = NULL, *st_mtime = NULL;
	char atime[maxn], mtime[maxn];
	
	if(stat(argv[1], &statbuf) < 0)
		err_ret("%s: stat error", argv[1]);
	st_atime = localtime(&statbuf.st_atime);
	st_mtime = localtime(&statbuf.st_mtime);

	strftime(atime, sizeof(atime), "%Y-%m-%d, %H:%M:%S", st_atime);
	strftime(mtime, sizeof(mtime), "%Y-%m-%d, %H:%M:%S", st_mtime);

	printf("atime: %s\n", atime);
	printf("mtime: %s\n", mtime);
	exit(0);
}
