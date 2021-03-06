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
const int N = 100000 + 7;
typedef unsigned long long ull;
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
int n, m, sx, sy, dx, dy;
vector<vector<char>>grid;
vector<vector<int>>dist;
int dirx[] = { 0,0,-1,1 };
int diry[] = { 1,-1,0,0 };
bool valid(int x, int y)
{
	return x > -1 && x<n&&y>-1 && y < m&&grid[x][y] != 'X';
}
struct edge
{
	pair<int, int> wer; int w;
	edge(pair<int, int> f, int ww)
	{
		wer = f, w = ww;
	}
	bool operator <(const edge &e)const
	{
		return w > e.w;
	}
};
int dijkstra(int sx, int sy, int dx, int dy)
{
	bool ok = false;
	int cost;
	dist[sx][sy] = 0;
	priority_queue<edge>pq;
	pq.push(edge({ sx ,sy }, 0));
	while (!pq.empty() && !ok)
	{
		edge e = pq.top(); pq.pop();
		if (e.w > dist[e.wer.first][e.wer.second])continue;
		for (int i = 0; i < 4 && !ok; i++)
		{
			int tox = e.wer.first+dirx[i], toy = e.wer.second+diry[i];
			if (valid(tox, toy))
			{
				if (grid[tox][toy] == 'D')
					return dist[e.wer.first][e.wer.second];
				if (grid[tox][toy] == 'S')continue;
				if (dist[e.wer.first][e.wer.second] + (grid[tox][toy] - '0') < dist[tox][toy])
				{
					dist[tox][toy] = dist[e.wer.first][e.wer.second] + (grid[tox][toy] - '0');
					pq.push(edge({ tox,toy }, dist[tox][toy]));
				}
			}
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	while (scanf("%d%d", &m, &n)&&m+n!=0)
	{
		grid.clear(), dist.clear();
		grid.resize(n), dist.resize(n);
		for (int i = 0; i < n; i++)
			grid[i].resize(m), dist[i].resize(m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				scanf(" %c", &grid[i][j]);
				dist[i][j] = 1e9;
				if (grid[i][j] == 'S')
					sx = i, sy = j;
				else if (grid[i][j] == 'D')
					dx = i, dy = j;
			}
		printf("%d\n", dijkstra(sx, sy, dx, dy));
	}
	return 0;
}
