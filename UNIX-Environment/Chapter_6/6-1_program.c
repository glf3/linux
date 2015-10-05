#include <pwd.h>
#include <stddef.h>
#include <string.h>

struct passwd *getpwnam(const char *name)
{
	struct passwd *ptr;
	setpwent();
	while((ptr = getpwent()) != NULL)
	{
		if(strcmp(name, ptr->pw_name) == 0)
			break;
	}
	endpwent();
	return (ptr);
}

int main(void)
{
	char name[10] = "forest";
	struct passwd *ptr1 = getpwnam(name);
	if(ptr1 == NULL)
		printf("No\n");
	else
		printf("Yes\n");
	struct passwd *ptr2 = getpwnam("just for fun");
	if(ptr2 == NULL)
		printf("No\n");
	else
		printf("Yes\n");
	exit(0);
}
