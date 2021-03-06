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
typedef long long ll;
typedef unsigned long long ull;
const double PI = acos(-1.0);
const double  EPS = 1e-11;
const ll MOD = 1000000007;
const int N = 100000 + 7;
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
int n;
vector<int>prev, cur;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	scanf("%d", &n);
	prev.resize(n);
	cur.resize(n);
	for (int &i : rev)scanf("%d", &i);
	cur = prev;
	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j < n-1; j++)
		{
			if (cur[j - 1] + cur[j] + cur[j + 1] <= 1)
				cur[j] = 0;
			else
				cur[j] = 1;
		}
		if (cur == prev)
		{
			printf("%d\n", i - 1);
			for (int &i : cur)printf("%d ", i);
			puts("");
			return 0;
		}
	}
	puts("-1");
	return 0;
}