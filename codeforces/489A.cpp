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

int main()
{
	ll n,x;
	cin >> n;
	vector<ll> v;
	vector<ll> v1;
	vector<pair<ll,ll> > p;
	pair<ll,ll> p1;
	for(ll i=0;i<n;i++)
	{
		cin >> x;
		v.push_back(x);
		//v1.push_back(x);
	}
	//sort(v1.begin(),v1.end());
	ll ct=0,idx;
	for(ll i=0;i<n;i++)
	{
		idx=i;
		for(ll j=i;j<n;j++)
		{
			if(v[j]<v[idx])
			{
				idx=j;
			}
		}
		if(idx!=i)
		{
			p1.first=min(i,idx);
			p1.second=max(i,idx);
			p.push_back(p1);
			ct++;
			swap(v[i],v[idx]);
		}	
	}
	cout << ct << endl;
	for(int i=0;i<p.size();i++)
	{
		cout << p[i].first << " " << p[i].second << endl;
	}
	return 0;
}
