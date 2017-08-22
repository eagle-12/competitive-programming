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

using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	vector<pair<int,pair<int,int> > > v(n);
	for(int i=0;i<n;i++)
	{
		cin >> v[i].se.fi;
	}
	for(int i=0;i<n;i++)
	{
		cin >> v[i].se.se;
		v[i].fi = v[i].se.fi-v[i].se.se;
	}
	sort(v.begin(),v.end());
	ll ans=0;
	int ct=0;
	int i=0;
	for(i=0;i<n;i++)
	{
		if(v[i].fi<=0)
		{
			ans+=v[i].se.fi;
			ct++;
		}
		else
		{
			break;
		}
	}
	//cout << ans << endl;
	if(ct<k)
	{
		for(int j=i;j<n;j++)
		{
			if(ct<k)
			{
				ans+=v[j].se.fi;
				ct++;
			}
			else
			{
				ans+=v[j].se.se;
			}
		}
	}
	else
	{
		for(int j=i;j<n;j++)
		{
			ans+=v[j].se.se;	
		}
	}
	cout << ans << endl;
}
