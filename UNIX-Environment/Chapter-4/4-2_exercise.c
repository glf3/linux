#include "apue.h"

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(void)
{
	umask(0);
	if(creat("foo2", RWRWRW) < 0)
		err_sys("creat error for fo2");
	umask(S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP | S_IROTH | S_IWOTH | S_IXOTH);
	if(creat("bar2", RWRWRW) < 0)
		err_sys("creat error for bar2");
	exit(0);
}
