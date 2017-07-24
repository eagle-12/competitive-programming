#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,x,y,flag=1,i;
	cin >> n;
	int arr2[n]={0};
	cin >> x;
	int arr[x];
	for(i=0;i<x;i++)
	{
		cin >> arr[i];
		arr2[arr[i]-1]++;
	}
	cin >> y;
	int arr1[y];
	for(i=0;i<y;i++)
	{
		cin >> arr1[i];
		arr2[arr1[i]-1]++;
	}
	sort(arr2,arr2+n);
	for(i=0;i<n;i++)
	{
		if(arr2[i]==0)
		{
			flag=0;
			break;
		}
		else
		{
			flag=1;
		}
	}
	if(flag==0)
	{
		cout << "Oh, my keyboard!";
	}
	else
	{
		cout << "I become the guy.";
	}
}
