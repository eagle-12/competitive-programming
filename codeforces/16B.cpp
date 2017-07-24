#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	vector<pair<int,int> > v(m);
	for(int i=0;i<m;i++)
	{
		cin >> v[i].second >> v[i].first;
	}
	sort(v.begin(),v.end());
	int ans=0;
	for(int i=m-1;i>=0;i--)
	{
		if(v[i].second>n)
		{
			ans+=v[i].first*n;
			break;
		}
		else
		{
			ans+=(v[i].first)*(v[i].second);
			n-=v[i].second;
		}
	}
	cout << ans;
}
