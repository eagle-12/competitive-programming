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

int ct[200001]={0};

int main()
{
	_cin;
	int n,k=0;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		ct[arr[i]]++;
	}
	vector<int> v;
	for(int i=1;i<=n;i++)
	{
		if(ct[i]==0)
		{
			v.pb(i);
		}
	}
	cout << v.size() << endl;
	for(int i=0;i<n;i++)
	{
		if(ct[arr[i]]==1)
		{
			cout << arr[i] << " ";
		}
		else if(ct[arr[i]]==-1)
		{
			cout << v[k++] << " ";
		}
		else
		{
			if(arr[i]<v[k])
			{
				cout << arr[i] << " ";
				ct[arr[i]]=-1;
			}
			else
			{
				cout << v[k++] << " ";
				ct[arr[i]]--;
			}
		}
	}
	return 0;
}
