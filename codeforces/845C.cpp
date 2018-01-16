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
	ll n,x,y,j=0;
	cin >> n;
	vector<pair<ll,ll> > v(2*n);
	for(int i=0;i<n;i++)
	{
		cin >> x >> y;
		v[j].fi=x;
		v[j++].se=0;
		v[j].fi=y;
		v[j++].se=1;
	}
	sort(v.begin(),v.end());
	int ct=0;
	int pre;
	for(int i=0;i<2*n;i++)
	{
		if(ct>=3)
		{
			cout << "NO" << endl;
			return 0;
		}
		if(v[i].se==0)
		{
			ct++;
		}
		else
		{
			ct--;
		}
	}
	if(ct>=3)
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	return 0;
}
