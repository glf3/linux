#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <set>
#include <iostream>
#include <cstring>
#include <string>
#include <bitset>
using namespace std;
const int maxn = 5000000 + 10;
bitset<maxn> B;
set<long long> M;
int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		M.clear();
		B.reset();
		//memset(hash, 0, sizeof(hash));
		for(int i = 0; i < n; i++)
		{
			int x; scanf("%d", &x);
			if(M.count(x)) B.set(i);
			else M.insert(x);
		}
		for(int i = 0; i < n; i++)
			printf("%d", B[i]?1:0);
		printf("\n");
	}
	return 0;
}
