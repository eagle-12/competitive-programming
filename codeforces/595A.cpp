#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;


#define ll long long int

int main()
{
	int n,m;
	cin >> n >> m;
	int arr[n][2*m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2*m;j++)
		{
			cin >> arr[i][j];
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2*m;j++)
		{
			ans+=arr[i][j]|arr[i][j+1];
			j++;
		}
	}
	cout << ans << endl;
}
