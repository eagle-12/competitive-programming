#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,flag=-1;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	sort(arr,arr+n);
	for(int i=0;i<=n-3;i++)
	{
		if(arr[i]+arr[i+1]>arr[i+2])
		{
			flag=0;
			break;
		}
	}
	if(flag==0)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}
