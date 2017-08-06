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

bool check(int m,int s)
{
	return (s>=0 && s<=9*m);
}

int main()
{
	int m,s;
	cin >> m >> s;
	int sum=s;
	string mn,mx;
	if(s==0 && m==1)
	{
		cout << "0 0" << endl;
		return 0;
	}
	if(s==0 && m>1)
	{
		cout << "-1 -1" << endl;
		return 0;
	}
	if(!check(m,s))
	{
		cout << "-1 -1" << endl;
		return 0;
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<10;j++)
		{
			if((i>0 || j>0 || (m==1 && j==0)) && check(m-i-1,sum-j))
			{
				mn+=char('0'+j);
				sum-=j;
				//cout << j << endl;
				break;
			}
		}
	}
	sum=s;
	for(int i=0;i<m;i++)
	{
		for(int j=9;j>=0;j--)
		{
			if(check(m-i-1,sum-j) && (!(i==0 && j==0 && m!=1)))
			{
				mx+=char('0'+j);
				sum-=j;
				break;
			}
		}
	}
	cout << mn << " " << mx << endl;
	return 0; 
}
