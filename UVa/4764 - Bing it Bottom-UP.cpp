// ~/BAU/ACM-ICPC/Teams/Rampage/Abukhadijah
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
int n;
vector<int>nex, last, dp, arr;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	while (scanf("%d", &n) && n != 0)
	{
		last.clear();
		arr.clear();
		nex.clear();
		dp.clear();
		last.resize(N, -1);
		nex.resize(n);
		dp.resize(n + 7);
		arr.resize(n);
		for (int &i : arr)scanf("%d", &i);
		for (int i = n - 1; i > -1; i--)
		{
			nex[i] = last[arr[i]];
			last[arr[i]] = i;
		}
		for (int i = n - 1; i >= 0; i--)
		{
			dp[i] = dp[i + 1];
			if (nex[i] != -1)
				dp[i] = max(dp[i], dp[nex[i]] + ((arr[i] == 999) ? 3 : 1));
		}
		printf("%d\n", dp[0]);
	}
	return 0;
}
