#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back
#define fi first
#define se second
#define mp make_pair

#define lb(x, k)   lower_bound(all(x), k)-x.begin()
//first element not less than (i.e. greater or equal to) k
#define ub(x, k)   upper_bound(all(x), k)-x.begin()
//first element greater than k


ll mod = 1000000007;

using namespace std;

int main()
{
	ll n,k,d;
	cin >> n >> k >> d;
	ll ans[n+1][2];
	ans[0][0]=1;
	ans[0][1]=0;
	for(int i=1;i<=n;i++)
	{
		ans[i][0]=0;
		ans[i][1]=0;
		for(int j=1;j<=k;j++)
		{
			if(i>=j)
			{
				if(j<d)
				{
					ans[i][0]=(ans[i][0]+ans[i-j][0])%mod;
					ans[i][1]=(ans[i][1]+ans[i-j][1])%mod;
				}
				else
				{
					ans[i][1]=(ans[i][1]+ans[i-j][0]+ans[i-j][1])%mod;
				}
			}
			else
			{
				break;
			}
		}
	}
	//cout << ans[1][0] << " " << ans[1][1] << endl;
	cout << ans[n][1] << endl;
}
