#include "apue.h"
#include <unistd.h>

int main(void)
{
	int newfd = dup(1);
	printf("%d\n", newfd);
	return 0;
}
