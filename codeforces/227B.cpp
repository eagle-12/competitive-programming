#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	ll n,x;
	cin >> n;
	vector<ll> lf(n+1);
	vector<ll> rh(n+1);
	for(ll i=0;i<n;i++)
	{
		cin >> x;
		lf[x]=i+1;
		rh[x]=n-i;
	}
	ll m;
	cin >> m;
	ll ct1=0,ct2=0;
	for(ll i=0;i<m;i++)
	{
		cin >> x;
		ct1+=lf[x];
		ct2+=rh[x];
	}
	cout << ct1 << " " << ct2 << endl;
}
