#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,i,ct=0,flag=1;
	cin >> n;
	string s;
	cin >> s;
	int arr[26]={0};
	if(n>26)
	{
		cout << "-1";
	}
	else
	{
		for(i=0;i<n;i++)
		{
			arr[(int)s[i]-97]++;
		}
		for(i=0;i<26;i++)
		{	
			if(arr[i]>26)
			{
				cout << "-1";
				flag=0;
				break;
			}
			if(arr[i]>1)
			{
				ct=ct+arr[i]-1;
			}
		}
		if(flag==1)
		{
			cout << ct;
		}
	}	
}
