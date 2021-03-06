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
const int N = 109;
typedef unsigned long long ull;
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
int main()
{
	int tc, n;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d", &n);
		vector<int>seq(n), dp(n);
		for (int &i : seq)scanf("%d", &i);
		for (int i = 0; i < n; i++)
		{
			int mx = 0;
			for (int j = 0; j < i; j++)
			{
				if (seq[i] > seq[j])
					mx = max(mx, dp[j]);
			}
			dp[i] = mx + 1;
		}
		int ans = -1;
		for (int i = 0; i < n; i++)
			ans = max(ans, dp[i]);
		printf("%d\n", ans);
	}
	return 0;
}
