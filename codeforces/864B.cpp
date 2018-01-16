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
	int n,ans=0,ct;
	cin >> n;
	string s;
	cin >> s;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int arr[26]={0};
			ct=0;
			for(int k=i;k<=j;k++)
			{
				if(isupper(s[k]))
				{
					break;
				}
				else
				{
					if(arr[s[k]-'a']==0)
					{
						ct++;
						arr[s[k]-'a']=1;
					}
				}
			}
			ans=max(ans,ct);
		}
	}
	cout << ans << endl;
	return 0;
}
