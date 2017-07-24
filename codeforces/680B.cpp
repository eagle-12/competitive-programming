#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,a;
	cin >> n >> a;
	int arr[n+1];
	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
	} 
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		if(arr[i]==1)
		{
			int dis = i-a;
			int j = a - dis;
			if(j < 1 || j > n || arr[i] == arr[j])
			{
				ans++;;
			}
		}
	}
	cout << ans;	
}
