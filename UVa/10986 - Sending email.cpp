// ~/Remember,remember the 6th of March
#include <functional>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include<complex>
#include <unordered_map>
#include<unordered_set>
#include <numeric>
#include <string>
#include<iostream>
#include <fstream>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include<cmath>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
using namespace std;
const double PI = acos(-1.0);
const double  EPS = 1e-11;
typedef long long ll;
const ll MOD = 1000000007;
//const int N = 100000 + 7;
typedef unsigned long long ull;
//freopen("input.txt","r",stdin);
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
int n, m, tc, s, d;
struct edge
{
	int from, to, cost;
	edge(int f, int t, int c)
	{
		from = f, to = t, cost = c;
	}
	bool operator <(const edge &e)const
	{
		return cost > e.cost;
	}
};
vector< vector<edge>>adjl;
vector<int>dist;
void dijkstra(int s, int d)
{
	priority_queue<edge>pq;
	pq.push({ -1,s,0 });
	dist[s] = 0;
	while (!pq.empty())
	{
		edge e = pq.top(); pq.pop();
		if (e.cost > dist[e.to])continue;
		if (e.to == d)
			return;
		for (int i = 0; i < adjl[e.to].size(); i++)
		{
			edge ne = adjl[e.to][i];
			if (dist[ne.to] > dist[e.to] + ne.cost)
			{
				dist[ne.to] = ne.cost = dist[ne.from] + ne.cost;
				pq.push(ne);
			}
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &tc);
	int i = 1;
	while (tc--)
	{
		int u, v, c;
		scanf("%d%d%d%d", &n, &m, &s, &d);
		adjl.clear();
		dist.clear();
		adjl.resize(n);
		dist.resize(n, 2e9);
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &u, &v, &c);
			adjl[u].push_back({ u,v,c });
			adjl[v].push_back({ v,u,c });
		}
		dijkstra(s, d);
		if (dist[d] == 2e9)
			printf("Case #%d: unreachable\n", i);
		else
			printf("Case #%d: %d\n", i, dist[d]);
		i++;
	}
	return 0;
}
