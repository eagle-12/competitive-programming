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

ll ans[10000001]={0};

int main()
{
	_cin;
	int n;
	cin >> n;
	ans[0]=1;
	ans[1]=0;
	ans[2]=3;
	ll x=3;
	for(int i=3;i<=n;i++)
	{
		x=(x*3)%mod;
		ans[i]=((x-ans[i-1])+mod)%mod;
	}
	/*for(int i=0;i<30;i++)
	{
		if(ans[i]<0)
		{
			cout << i << endl;
		}
	}*/
	cout << ans[n] << endl;
}
