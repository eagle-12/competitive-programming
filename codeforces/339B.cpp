#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cmath>
using namespace std;


#define ll long long int

int main()
{
	ll n,m;
	cin >> n >> m;
	ll arr[m+1];
	ll ans=0;
	arr[0]=1;
	for(ll i=1;i<=m;i++)
	{
		cin >> arr[i];
	}
	ll curr=1;
	for(ll i=0;i<m;i++)
	{
		if(arr[i]>arr[i+1])
		{
			ans+=n-arr[i]+arr[i+1];
		}
		else
		{
			ans+=arr[i+1]-arr[i];
		}
	}
	cout << ans << endl;
}
