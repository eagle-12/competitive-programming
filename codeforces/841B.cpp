#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back


using namespace std;

int main()
{
	ll n;
	scanf("%lld",&n);
	ll arr[n];
	for(ll i=0;i<n;i++)
	{
		scanf("%lld",&arr[i]);
	}
	int ct=0;
	for(ll i=0;i<n;i++)
	{
		if(arr[i]%2==0)
		{
			ct++;
		}
	}
	if(ct==n)
	{
		cout << "Second" << endl;
	}
	else
	{
		cout << "First" << endl;
	}
	return 0;
}
