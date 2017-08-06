#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main()
{
	int n,ele=0;
	cin >> n;
	int arr[n];
	int ans=0,x=0;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	for(int i=0;i<=n-1;i++)
	{
		ele+=x-arr[i];
		if(ele<0)
		{
			ans-=ele;
			ele=0;
		}
		x=arr[i];
	}
	cout << ans << endl;
}
