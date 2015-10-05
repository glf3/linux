#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		int x; double y;
		double ans = 0; double t = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d%lf", &x, &y);
			ans += x*y; t += x*1.0;
		}
		printf("%.2lf\n", ans/t);
	}
	return 0;
}
