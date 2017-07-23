#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,ans = 0;
	cin >> n;
	int arr[n],dp[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		dp[i] = 0;
	}
	dp[0] = 1;
	for(int i=1;i<n;i++)
	{
		if(arr[i]>=arr[i-1])
		{
			dp[i] = dp[i-1] + 1;
		}
		else
		{
			dp[i] = 1;
		}
	}
	ans = dp[0];
	for(int i=1;i<n;i++)
	{
		ans = max(ans,dp[i]);
	}
	cout << ans;
}
