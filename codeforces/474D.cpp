#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back
#define fi first
#define se second
#define mp make_pair
#define _cin ios_base::sync_with_stdio(0);  cin.tie(0);

#define lb(x, k)   lower_bound(all(x), k)-x.begin()
//first element not less than (i.e. greater or equal to) k
#define ub(x, k)   upper_bound(all(x), k)-x.begin()
//first element greater than k


ll mod = 1000000007;

using namespace std;

ll ans[100005];

int main()
{
	_cin;
	ll t,k;
	cin >> t >> k;
	for(int i=0;i<k;i++)
	{
		ans[i]=1;
	}
	for(int i=k;i<100004;i++)
	{
		ans[i]=(ans[i-1]+ans[i-k])%mod;
	}
	for(int i=1;i<100004;i++)
	{
		ans[i]=(ans[i-1]+ans[i])%mod;
	}
	ll a,b;
	for(int i=0;i<t;i++)
	{
		cin >> a >> b;
		cout << (ans[b]-ans[a-1]+mod)%mod << endl;
	}
	return 0;
}
