#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,i,sum=0,ct=0,sum1=0;
	cin >> n;
	int arr[n];
	for(i=0;i<n;i++)
	{
		cin >> arr[i];
		sum=sum+arr[i];
	}
	sort(arr,arr+n);
	for(i=n-1;i>=0;i--)
	{
		sum1=sum1+arr[i];
		ct++;
		if(sum1>sum-sum1)
		{
			break;
		}
	}
	cout <<ct;
}
