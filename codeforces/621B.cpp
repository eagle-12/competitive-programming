#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int x,y;
	vector<pair<int,int> > v(n);
	int sum[2001]={0};
	int ct=0;
	map<int,int> diff;
	for(int i=0;i<n;i++)
	{
		cin >> x >> y;
		sum[x+y]++;
		if(diff.find(x-y)==diff.end())
		{
			diff[x-y]=1;
		}
		else
		{
			diff[x-y]+=1;
		}
	}
	for(int i=0;i<2001;i++)
	{
		if(sum[i]>1)
		{
			ct+=(sum[i]*(sum[i]-1))/2;
		}
	}
	map<int,int>::iterator itr;
	for(itr=diff.begin();itr!=diff.end();itr++)
	{
		ct+=((itr->second)*(itr->second-1))/2;
	}
	cout << ct;
}
