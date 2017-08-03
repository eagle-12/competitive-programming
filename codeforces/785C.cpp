#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	long long int n,m,ele;
	cin >> n >> m;
	if(n<=m)
	{
		cout << n << endl;
	}
	else
	{
		long long int low=0,high=2e9;
		while(low<high)
		{
			long long int mid=(low+high)/2;
			ele = ((mid)*(mid+1))/2;
			if(ele>=n-m)
			{
				high=mid;
			}
			else
			{
				low=mid+1;
			}
		}
		cout << m+low << endl;
	}
}
