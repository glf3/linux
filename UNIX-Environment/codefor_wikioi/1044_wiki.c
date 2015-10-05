#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 30;
int a[maxn];
int d[maxn];
bool vis[maxn];

int n;
int main()
{
	int x;
	while(~scanf("%d", &x) && x != -1)
	{
		a[n++] = x;
	}
	
	int pre = INF;
	memset(vis, 0, sizeof(vis));
	
	int color = 0;
	for(int i = 0; i < n; i++) if(!vis[i])
	{
		color++;
		pre = a[i];
		for(int j = i; j < n; j++) if(a[j] <= pre && !vis[j])
		{
			vis[j] = color;
			pre = a[j];
		}
	}

	for(int i = 0; i < n; i++)
	{
		d[i] = 1;
		int t = 0;
		for(int j = 0; j < i; j++) if(a[j] >= a[i])
			t = max(t, d[j]);
		d[i] += t;
	}
	int ans = -1;
	for(int i = 0; i < n; i++) ans = max(ans, d[i]);
	printf("%d\n%d\n", ans, color);
	return 0;
}
