#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back


using namespace std;

ll search(ll arr[],ll low,ll high,ll key)
{
	ll n = high+1;
	while(low<=high)
	{
		ll mid=(high+low)/2;
		if(arr[mid]==key)
		{
			return mid+1;
		}
		else if(arr[mid]>key && mid!=0 &&arr[mid-1]<key)
		{
			return mid;
		}
		else if(arr[mid]>key && mid==0)
		{
			return 0;
		}
		else if(arr[mid]<key && mid!=n-1 && arr[mid+1]>key)
		{
			return mid+1;
		}
		else if(arr[mid]<key && mid==n-1)
		{
			return n;
		}
		else if(arr[mid]>key)
		{
			high = mid-1;
		}
		else if(arr[mid]<key)
		{
			low = mid+1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	ll n;
	cin >> n;
	ll arr[n];
	for(ll i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	sort(arr,arr+n);
	ll q,x,ans;
	cin >> q;
	for(ll i=0;i<q;i++)
	{
		cin >> x;
		ans = upper_bound(arr,arr+n,x)-arr;
		cout << ans << endl;
	}
}
