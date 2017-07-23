#include <bits/stdc++.h>

using namespace std;

int b[1000000]={0},dp[1000001]={0};

int main()
{
	int n;
	cin >> n;
	//int b[1000000]={0},dp[1000001]={0};
	int x,y;
	for(int i=0;i<n;i++)
	{
		cin >> x >> y;
		b[x] = y;
	}
	if(b[0]>0)
	{
		dp[0] = 1;
	}
	for(int i=1;i<1000001;i++)
	{
		if(b[i]==0)
		{
			dp[i] = dp[i-1];
		}
		else
		{
			if(b[i]>=i)
			{
				dp[i] = 1;
			}
			else
			{
				dp[i] = dp[i-b[i]-1] + 1;
			}
		}
	}
	int ans = dp[0];
	for(int i=1;i<1000001;i++)
	{
		ans = max(ans,dp[i]);
	}
	cout << n - ans << endl;
}
