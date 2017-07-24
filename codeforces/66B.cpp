#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	int ans = 0,ele;
	int ct=1;
	//int ct1=0;
	if(n==1)
	{
		cout << 1;
		return 0;
	}
	//int ele = arr[0];
	//int ans = 0;
	//int ct = 1;
	for(int i=1;i<n;i++)
	{
		if(arr[i]>arr[i-1])
		{
			break;
		}
		else if(arr[i]<=arr[i-1])
		{
			ct++;
		}
	}
	ans = max(ans,ct);
	for(int i=1;i<n-1;i++)
	{
		ct = 1;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]>arr[j-1])
			{
				break;
			}
			else
			{
				ct++;
			}
		}
		for(int j=i-1;j>=0;j--)
		{
			if(arr[j]>arr[j+1])
			{
				break;
			}
			else
			{
				ct++;
			}
		}
		ans = max(ct,ans);
	}
	ct = 1;
	for(int j=n-2;j>=0;j--)
	{
		if(arr[j]>arr[j+1])
		{
			break;
		}
		else
		{
			ct++;
		}
	}
	ans = max(ans,ct);
	cout << ans;
}
