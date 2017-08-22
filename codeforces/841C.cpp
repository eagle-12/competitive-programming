#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back


using namespace std;

int main()
{
	ll n,m;
	scanf("%lld",&m);
	ll a[m],b[m];
	vector<pair<ll,ll> > v(m);
	ll ans[m];
	for(ll i=0;i<m;i++)
	{
		scanf("%lld",&a[i]);

	}
	for(ll i=0;i<m;i++)
	{
		scanf("%lld",&b[i]);
		v[i].first=b[i];
		v[i].second=i;
	}
        sort(a,a+m);
	sort(v.begin(),v.end());
	//sort(b,b+m);
	ll ele;
	for(ll i=0;i<m;i++)
	{
		ans[v[i].second]=a[m-1-i];
	}
	for(ll i=0;i<m;i++)
	{
		printf("%lld ",ans[i]);
	}
	return 0;
}
