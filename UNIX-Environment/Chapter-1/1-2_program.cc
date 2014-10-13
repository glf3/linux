/*
  print what you READIN.
/
include "apue.h"

const int size = 1024;

int main(void)
{
	int n;
	char buf[size];
	while((n = read(STDIN_FILENO, buf, size)) > 0) //最多读size数据
	{
		printf("The size of READIN: %d\n", n); //返回值为读入字节大小
		if(write(STDOUT_FILENO, buf, n) != n) //每次写入实际写入数据
			err_sys("write error");
	}
	if(n < 0)
		err_sys("read error");
}
