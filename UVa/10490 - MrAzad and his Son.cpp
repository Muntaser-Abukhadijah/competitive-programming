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
ll n;
ll fastpower(ll num, ll pow)
{
	if (pow == 0)
		return 1;
	ll ans = fastpower(num, pow / 2);
	ans = ans * ans;
	if (pow & 1)
		ans *= num;
	return ans;
}
bool isprime(ll num)
{
	if (num == 2)
		return 1;
	if (num < 2 || num % 2 == 0)
		return 0;
	for (ll i = 3; i*i <= num; i += 2)
		if (num%i == 0)
			return 0;
	return 1;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	while (scanf("%lld", &n)!=EOF && n != 0)
	{
		if (isprime(n))
		{
			ll t = fastpower(2, n);
			if (isprime(t - 1))
				printf("Perfect: %lld!\n", (t - 1)*fastpower(2, n - 1));
			else
				puts("Given number is prime. But, NO perfect number is available.");
		}
		else
			puts("Given number is NOT prime! NO perfect number is available.");
	}
	return 0;
}
