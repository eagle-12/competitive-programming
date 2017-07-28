#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back


using namespace std;
ll ct[1000010]={0};
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	ll n;
	cin >> n;
	vector<ll> v;
	ll x,sum=0;
	for(ll i=0;i<n;i++)
	{
		cin >> x;
		v.pb(x);
		sum+=x;
	}
	if(sum%3!=0)
	{
		cout << 0 << endl;
	}
	else
	{
		sum=sum/3;
		ll s=0;
		for(ll i=n-1;i>=0;i--)
		{
			s+=v[i];
			if(s==sum)
			{
				ct[i]=1;
			}
		}
		for(ll i=n-2;i>=0;i--)
		{
			ct[i]+=ct[i+1];
		}
		ll ans=0;
		s=0;
		for(ll i=0;i<n-2;i++)
		{
			s+=v[i];
			if(s==sum)
			{
				ans+=ct[i+2];
			}
		}
		cout << ans << endl;
	}
}
