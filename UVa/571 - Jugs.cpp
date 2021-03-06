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
int A, B, N;
struct state { int a, b, action; };
state path[1009][1009];
bool vis[1009][1009];
queue<state>qu;
vector<string>steps = { "fill B", "fill A", "empty B", "empty A", "pour B A", "pour A B", "Start" };
enum list			  { FILL_B,    FILL_A,   EMPTY_B,   EMPTY_A,   POUR_B_A,   POUR_A_B,   Start  };
void add_state(int a, int b, int act, state prev)
{
	if (vis[a][b])
		return;
	state temp = { a, b, act };
	qu.push(temp);
	path[a][b] = prev;
	vis[a][b] = 1;
}
void backtrace(state req)
{
	if (req.a == 0&& req.b == 0)
		return;
	backtrace(path[req.a][req.b]);
	cout << steps[req.action] << "\n";
}
void BFS()
{
	qu = queue<state>();
	memset(vis, 0, sizeof(vis));
	add_state(0, 0, Start, state());
	while (!qu.empty())
	{
		int aa, bb;
		state cur = qu.front(); qu.pop();
		if (cur.b == N)
		{
			backtrace(cur);
			puts("success");
			return;
		}
		add_state(cur.a, B, FILL_B, cur);
		add_state(A, cur.b, FILL_A, cur);
		add_state(cur.a, 0, EMPTY_B, cur);
		add_state(0, cur.b, EMPTY_A, cur);
		aa = cur.b > A - cur.a ? A : cur.a + cur.b;
		bb = cur.b > A - cur.a ? cur.b - (A - cur.a) : 0;
		add_state(aa, bb, POUR_B_A, cur);
		aa = cur.a > B - cur.b ? cur.a-(B - cur.b) : 0;
		bb = cur.a > B - cur.b ? B : cur.b+cur.a;
		add_state(aa, bb, POUR_A_B, cur);
	
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	while (scanf("%d%d%d", &A, &B, &N)!=EOF)
		BFS();
	return 0;
}
