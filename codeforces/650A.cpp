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
	ll n,x,y;
	cin >> n;
	map<ll,vector<ll> > xp;
	map<ll,vector<ll> > yp;
	map<pair<ll,ll>,ll> po;
	pair<ll,ll> p;
	for(ll i=0;i<n;i++)
	{
		cin >> x >> y;
		p.first=x;
		p.second=y;
		if(po.find(p)==po.end())
		{
			po[p]=1;
		}
		else
		{
			po[p]++;
		}
		if(xp.find(x)==xp.end())
		{
			vector<ll> s;
			s.push_back(y);
			xp[x]=s;
		}
		else
		{
			xp[x].push_back(y);
		}
		if(yp.find(y)==yp.end())
		{
			vector<ll> s;
			s.push_back(x);
			yp[y]=s;
		}
		else
		{
			yp[y].push_back(x);
		}
	}
	map<ll,vector<ll> >::iterator itr;
	ll ans=0,ele;
	for(itr=xp.begin();itr!=xp.end();itr++)
	{
		ele=(itr->second).size();
		ans+=(ele*(ele-1))/2;
		/*if(ele>1)
		{
			cout << itr->first << endl;
		}*/
	}
	//cout << ans << endl;;
	for(itr=yp.begin();itr!=yp.end();itr++)
	{
		ele=(itr->second).size();
		ans+=(ele*(ele-1))/2;
	}
	map<pair<ll,ll>,ll>:: iterator it;
	for(it=po.begin();it!=po.end();it++)
	{
		ele=(it->second);
		ans-=(ele*(ele-1))/2;
	}	 
	cout << ans;
}
