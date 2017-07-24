#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,i,x,ct=0;
	cin >> n;
	int arr[4]={0};
	for(i=0;i<n;i++)
	{
		cin >> x;
		arr[x-1]++;
	}
	ct=ct+arr[3];
	ct=ct+arr[2];
	if(arr[0]>arr[2])
	{
		arr[0]=arr[0]-arr[2];
		if((arr[0]+arr[1]*2)%4==0)
		{
			ct=ct+(arr[0]+arr[1]*2)/4;
		}
		else
		{
			ct=ct+((arr[0]+arr[1]*2)/4)+1;
		}
	}
	else
	{
		arr[0]=0;
		ct=ct+(2*arr[1])/4+arr[1]%2;
		//cout << ct;
	}
	cout << ct;
}
