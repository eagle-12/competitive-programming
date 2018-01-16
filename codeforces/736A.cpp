#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back
#define fi first
#define se second
#define mp make_pair
#define _cin ios_base::sync_with_stdio(0);  cin.tie(0);

#define lb(x, k)   lower_bound(all(x), k)-x.begin()
//first element not less than (i.e. greater or equal to) k
#define ub(x, k)   upper_bound(all(x), k)-x.begin()
//first element greater than k


ll mod = 1000000007;

using namespace std;

vector<vector<int> > v(100001);
int col[100001]={0};
int vis[100001]={0};
int ct=0;
int el=-1;
int a,b;

void dfs(int ele)
{
	vis[ele]=1;
	ct++;
	int l=v[ele].size();
	for(int i=0;i<l;i++)
	{
		if(vis[v[ele][i]]==0)
		{
			if(col[ele]!=col[v[ele][i]])
			{
				el=ele;
				a=el;
				b=v[ele][i];
				break;
			}
		}
	}
	return;
}

void dfs1(int ele)
{
	vis[ele]=1;
	ct++;
	int l=v[ele].size();
	for(int i=0;i<l;i++)
	{
		if(vis[v[ele][i]]==0)
		{
			if(col[ele]!=col[v[ele][i]] /*&& !(ele==a && v[ele][i]==b)*/)
			{
				el=ele;
				break;
			}
		}
	}
	return;
}
int main()
{
	_cin;
	int n;
	cin >> n;
	int x,y;
	for(int i=0;i<n-1;i++)
	{
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	for(int i=0;i<n;i++)
	{
		cin >> col[i];
	}
	dfs(1);
	if(el==-1)
	{
		cout << "YES" << endl;
		cout << "1" << endl;
		return 0;
	}
	ct=0;
	x=el;
	el=-1;
	dfs1(x);
	if(el==-1)
	{
		cout << "YES" << endl;
		cout << x << endl; 
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}
