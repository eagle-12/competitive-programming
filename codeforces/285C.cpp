#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back


using namespace std;

int main()
{
	ll n,x;
	cin >> n;
	vector<ll> v;
	for(ll i=0;i<n;i++)
	{
		cin >> x;
		v.pb(x);
	}
	sort(v.begin(),v.end());
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=abs(v[i]-(i+1));
	}
	cout << ans << endl;
}
