#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back


using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	ll n,x,y,ans=0;
	cin >> n >> x;
	vector<ll> v;
	for(ll i=0;i<n;i++)
	{
		cin >> y;
		v.pb(y);
	}
	sort(v.begin(),v.end());
	ll j=0;
	while(x!=1 && j<n)
	{
		ans+=v[j]*x;
		j++;
		x--;
	}
	while(j<n)
	{
		ans+=v[j];
		j++;
	}
	cout << ans;
}
