#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 110;

int a[maxn];

int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		
		sort(a, a+n);

		int ans = 1;
		for(int i = 0; i < n-1; i++)
		{
			int dif = a[i+1]-a[i];
			int t = 1;
			int p = i;
			for(int j = i+1; j < n; j++)
			{
				if(a[j]-a[p] == dif)
				{
					p = j;
					t++;
				}
			}
			ans = max(ans, t);
		}
		printf("%d\n", ans);
	}
	return 0;
}
