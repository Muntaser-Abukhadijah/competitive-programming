#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <string>
#include <iostream>
#include <fstream>
#include<algorithm>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <cmath>
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
const double EPS = 1e-11;
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
int main()
{
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
#endif
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        cout<<abs((((n*63+7492)*5-498)/10)%10)<<endl;
    }
    
    return 0;
}
