#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

const int INF = 0x3f3f3f3f;

int d[15][15];

void Floyd()
{
	for(int k = 0; k < 10; k++)
	for(int i = 0; i < 10; i++)
	for(int j = 0; j < 10; j++)
		d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
}

void init()
{
	for(int i = 0; i < 10; i++)
	for(int j = 0; j < 10; j++)
		d[i][j] = (i == j)? 0:INF;
}

typedef long long LL;
#define readint(T) scanf("%d", &T)

int C[10];

int main()
{
	char n[50];
	int k;
	while(~scanf("%s%d", n, &k))
	{
		init();
		for(int i = 1; i <= k; i++)
		{
			int x, y; readint(x), readint(y);
			d[x][y] = 1;
		}

		Floyd();

		for(int i = 0; i < 10; i++) C[i] = 1;

		for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			if(d[i][j] != INF && i != j)
				C[i]++;
		/*for(int i = 0; i < 10; i++)
		{
			for(int j = 0; j < 10; j++)
			{
				printf("%d ", d[i][j]);
			}
			printf("\n");
		}
		for(int i = 0; i < 10; i++)
			printf("%d ", C[i]);
		printf("\n");*/
		LL ans = 1;
		int len = strlen(n);
		for(int i = 0; i < len; i++)
		{
			ans *= C[n[i]-'0'];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
