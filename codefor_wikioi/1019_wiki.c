#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 1010;
const int maxm = 100010*2;
const int INF = 0x3f3f3f3f;

bool G[maxn][maxn];

int n, m;
int cnt;
int first[maxn];

int d[maxn][maxn];

struct Edge
{
	int u, v, w;
	int next;
}edge[maxm];

void read_graph(int u, int v, int w)
{
	edge[cnt].v = v, edge[cnt].w = w;
        edge[cnt].next = first[u], first[u] = cnt++;
}

void spfa(int s)
{
	queue<int> Q;
	bool inq[maxn] = {0};
	
	Q.push(s); inq[s] = 1;
	while(!Q.empty())
	{
		int x = Q.front(); Q.pop();
		inq[x] = 0;
		for(int e = first[x]; e != -1; e = edge[e].next)
		{
			int v = edge[e].v, w = edge[e].w;
			if(d[s][v] > d[s][x]+w)
			{
				d[s][v] = d[s][x]+w;
				if(!inq[v])
				{
					inq[v] = 1;
					Q.push(v);
				}
			}
		}
	}
}

void init()
{
	cnt = 0;
	memset(first, -1, sizeof(first));

	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n; j++)
		d[i][j] = (i == j)?0:INF;
}

int main()
{
	int T;
	for(scanf("%d", &T); T > 0; T--)
	{
		scanf("%d%d", &n, &m);
		
		init();
		memset(G, 0, sizeof(G));
		for(int i = 0; i < m; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			G[x][y] = 1;
			read_graph(x, y, 1);
		}

		for(int i = 1; i <= n; i++)
			spfa(i);
		
		int ok = 1;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++) if(i != j)
			{
				if(d[i][j] != INF && !G[i][j])
					{ok = 0; break; }
			}
			if(!ok) break;
		}
		printf(ok == 0?"No\n":"Yes\n");
	}
	return 0;
}
