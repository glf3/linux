#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
using namespace std;

set<int> S;
int main(void)
{
	int T;
	for(scanf("%d", &T); T > 0; T--)
	{	
		S.clear();
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if(a == c || b == c )
		{
			printf("Yes\n");
			continue;
		}

		S.insert(c);
		
		int flag = 0;
		for(;;)
		{
			int t = a+b;
			if(t > c) break;
			if(S.count(t)) { flag = 1; break; }
			a = b;
			b = t;
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
