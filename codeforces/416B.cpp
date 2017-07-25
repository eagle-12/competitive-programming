#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int m,n;
	cin >> m >> n;
	int arr[m+1][n+1],ans[m+1][n+1];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin >> arr[i][j];
		}
	}
	ans[1][1]=arr[1][1];
	for(int i=2;i<=n;i++)
	{
		ans[1][i]=ans[1][i-1]+arr[1][i];
	}
	for(int i=2;i<=m;i++)
	{
		ans[i][1] = ans[i-1][1]+arr[i][1];
	}
	for(int i=2;i<=m;i++)
	{
		for(int j=2;j<=n;j++)
		{
			ans[i][j] = max(ans[i-1][j],ans[i][j-1])+arr[i][j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << ans[i][n] << " ";
	}
}
