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
	int n,ans=0;
	cin >> n;
	vector<pair<int,int> > v(n);
	vector<pair<int,pair<int,int> > > v1(n);
	for(int i=0;i<n;i++)
	{
		cin >> v[i].first >> v[i].second;
		v1[i].first=0;
		v1[i].second.first=0;
		v1[i].second.second=0;
	}
	int st=0,lf=v[0].first,rh=0;
	int ct=1;
	if(n==1)
	{
		cout << 1 << endl;
		return 0;
	}
	for(int i=1;i<n-1;i++)
	{
		if((v[i].first-v[i].second)>lf)
		{
			ct++;
			lf=v[i].first;
		}
		else
		{
			if((v[i].first+v[i].second)<v[i+1].first)
			{
				ct++;
				lf=v[i].first+v[i].second;
			}
			else
			{
				lf=v[i].first;
			}
		}
	}
	cout << ct+1 << endl;
	/*v1[0].first=0;
	v1[0].second.first=1;
	if(n==1)
	{
		v1[0].second.second=1;
		cout << 1 << endl;
		return 0;
	}
	else
	{
		if(v[1].first>(v[0].first+v[0].second))
		{
			v1[0].second.second=1;
		}
	}
	*/
	//cout << v1[0].second.second << endl;
	/*for(int i=1;i<n-1;i++)
	{
		v1[i].first=max(v1[i-1].first,max(v1[i-1].second.first,v1[i-1].second.second));
		if((v[i].first-v[i].second)>v[i-1].first)
		{
			v1[i].second.first=max(v1[i-1].first,max(v1[i-1].second.first,v1[i-1].second.second))+1;
		}
		else
		{
			v1[i].second.first=max(v1[i-1].first,max(v1[i-1].second.first,v1[i-1].second.second));
		}
		if((v[i].first+v[i].second)<v[i+1].first)
		{
			v1[i].second.second=max(v1[i-1].first,max(v1[i-1].second.first,v1[i-1].second.second))+1;
		}
		else
		{
			v1[i].second.second=max(v1[i-1].first,max(v1[i-1].second.first,v1[i-1].second.second));
		}
	}
	v1[n-1].first=max(v1[n-2].first,max(v1[n-2].second.first,v1[n-2].second.second));
	if((v[n-1].first-v[n-1].second)>v[n-2].first)
	{
		v1[n-1].second.first=max(v1[n-2].first,max(v1[n-2].second.first,v1[n-2].second.second))+1;
	}
	v1[n-1].second.second=max(v1[n-2].first,max(v1[n-2].second.first,v1[n-2].second.second))+1;*/
	//cout << max(v1[n-1].first,max(v1[n-1].second.first,v1[n-1].second.second)) << endl;
}
