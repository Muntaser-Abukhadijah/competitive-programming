// ~/BAU/ACM-ICPC/Teams/Rampage/Abukhadijah
// ~/Remember,remember the 6th of March.
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
const int N = 10000007;
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
string all = "0123456789ABCDEF";
string DtoA(int num, int base)
{
	string ans = "";
	while (num)
	{
		ans = all[num%base] + ans;
		num /= base;
	}
	return ans;
}
int AtoD(string s, int base)
{
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
	{
		ans *= base;
		ans += all.find(s[i]);
	}
	return ans;
}
int main()
{
	int num, base;
	cin >> num >> base;
	string s = DtoA(num, base);
	int n = AtoD(s, base);
	cout << s << " , " << n << endl;
	return 0;
}
