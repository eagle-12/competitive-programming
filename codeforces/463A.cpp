#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main()
{
	int n,s;
	cin >> n >> s;
	vector<pair<int,int> > v(n);
	for(int i=0;i<n;i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	int ans=101,ct=0,ct1=0;
	for(int i=0;i<n;i++)
	{
		if(v[i].first<s)
		{
			ct1++;
		}
		else if(v[i].first==s && v[i].second==0)
		{
			ct1++;
		}
		if(v[i].first<s && v[i].second!=0)
		{
			ans=min(v[i].second,ans);
			ct++;
		}
	}
	//cout << ct1 << endl;
	//cout << ans << endl;
	if(100-ans!=-1)
	{
		cout << 100-ans << endl;
		return 0;
	}
	if(ct==0 && ans==101)
	{
		if(ct1==0)
		{
			cout << -1 << endl;
			return 0;
		}
		cout << 0 << endl;
		return 0;
	}
}
