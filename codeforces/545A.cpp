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
	int n;
	cin >> n;
	int arr[n][n];
	vector<int> ans;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> arr[i][j];
		}
	}
	int flag=0,ct=0;
	for(int i=0;i<n;i++)
	{
		flag=0;
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]==1 || arr[i][j]==3)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			ct++;
			ans.push_back(i+1);
		}
	}
	cout << ct << endl;
	for(int i=0;i<ans.size();i++)
	{
		cout << ans[i] << " "; 
	}
	cout << endl;
	return 0;
}
