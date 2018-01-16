#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back
#define fi first
#define se second
#define mp make_pair
#define _cin ios_base::sync_with_stdio(0);  cin.tie(0);

#define lb(x, k)   lower_bound(all(x), k)-x.begin()
//first element not less than (i.e. greater or equal to) k
#define ub(x, k)   upper_bound(all(x), k)-x.begin()
//first element greater than k


ll mod = 1000000007;

using namespace std;

int main()
{
	_cin;
	int n;
	cin >> n;
	vector<int> v,v1;
	int arr[n],vis[n+1];
	for(int i=0;i<n+1;i++)
	{
		vis[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		
		if(arr[i]<=n)
		{
			if(vis[arr[i]]==1)
			{
				v.pb(i);
			}
			else
			{
				vis[arr[i]]=1;
			}
		}
		else if(arr[i]>n)
		{
			v.pb(i);
		}
	}
	//cout << vis[1] << vis[2] << vis[3] << endl;
	int k=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			v1.pb(i);
		}
	}
	//cout << v1[0] << endl;
	int i;
	if(v.size()!=0)
	{
		for(i=0;i<n;i++)
		{
			if(i!=v[k])
			{
				cout << arr[i] << " ";
			}
			else
			{
				cout << v1[k] << " ";
				k++;
				if(k==v.size())
				{
					break;
				}			
			}
		}
		for(int j=i+1;j<n;j++)
		{
			cout << arr[j] << " ";
		}
	}
	else
	{
		for(i=0;i<n;i++)
		{
			cout << arr[i] << " ";
		}
		
	}
	return 0;
}
