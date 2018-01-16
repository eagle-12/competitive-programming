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

int main()
{
	_cin;
	int n,d;
	cin >> n >> d;
	vector<pair<int,int> > v(n);
	for(int i=0;i<n;i++)
	{
		cin >> v[i].fi >> v[i].se;
	}
	sort(v.begin(),v.end());
	int ans=0;
	int i=1,j=0;
	if(n==1)
	{
		ans+=v[0].se;
	}
	for(int i=1;i<n;i++)
	{
		if((v[i].fi-v[i-1].fi)<d)
		{
			ans+=v[i].se;
		}
	}
	if((v[n-1].fi-v[n-2].fi)<d)
	{
		ans+=v[n-1].se;
	}
	cout << ans << endl;
	return 0;
}
