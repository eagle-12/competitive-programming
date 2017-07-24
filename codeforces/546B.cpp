#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,ct=0,i;
	cin >> n;
	int arr[n],arr1[2*n]={0};
	for(i=0;i<n;i++)
	{
		cin >> arr[i];
		arr1[arr[i]-1]++;
	}
	i=0;
	while(i<2*n)
	{
		if(arr1[i]==0 || arr1[i]==1)
		{
			i++;
		}
		else
		{	
			arr1[i+1]=arr1[i+1]+arr1[i]-1;
			ct=ct+arr1[i]-1;
			i++;
		}
	}
	cout << ct;
}
