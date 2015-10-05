#include "apue.h"
#include <sys/resource.h>
#include <unistd.h>
#include <limits.h>
int main()
{
	printf("%lu\n", LONG_MAX);
	printf("%lu\n", RLIM_INFINITY);
	return 0;
}
