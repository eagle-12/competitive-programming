#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cmath>
using namespace std;


#define ll long long int

int main()
{
	int n;
	cin >> n;
	int arr[n];
	int no=0;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		no+=arr[i];
	}
	int ct=0;
	int i=0;
	while(i<n)
	{
		if(arr[i]==1)
		{
			no--;
			ct++;
			int j=i+1;
			int flag=0;
			while(j<n)
			{
				if(arr[j]==1)
				{
					ct++;
					no--;
				}
				else
				{
					flag=1;
					break;
				}
				j++;
			}
			if(no==0)
			{
				break;
			}
			if(flag==1)
			{
				ct++;
			}
			i=j+1;
		}
		else
		{
			i++;
		}
	}
	cout << ct << endl;
}
