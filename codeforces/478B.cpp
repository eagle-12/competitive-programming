#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back
#define fi first
#define se second
#define mp make_pair

#define lb(x, k)   lower_bound(all(x), k)-x.begin()
//first element not less than (i.e. greater or equal to) k
#define ub(x, k)   upper_bound(all(x), k)-x.begin()
//first element greater than k


ll mod = 1000000007;

using namespace std;

int main()
{
	ll n,m;
	ll mn=0,mx=0;
	cin >> n >> m;
	mx = ((n-m+1)*(n-m))/2;
	ll a,b;
	a = n/m;
	b = n%m;
	mn = ((m-b)*(a*(a-1))/2);
	mn+= b*((a+1)*(a))/2;
	cout << mn << " " << mx;
	return 0;
}
