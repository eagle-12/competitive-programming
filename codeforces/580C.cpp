#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back


using namespace std;

vector<vector<int> > v(100001);
int n,m,ans=0;
//int flag[100001] = {0};
//vector<pair<int,int> > cat(100001);
int arr[100001] = {0};

/*void dfs(int ele,int par)
{
	flag[ele] = 1;
	cat[ele].first= arr[ele]+cat[par].first;
	int ct=0;
	for(int i=0;i<v[ele].size();i++)
	{
		if(flag[v[ele][i]]==0)
		{
			ct++;
			dfs(v[ele][i],ele);
		}
	}
	if(ct==0)
	{
		cat[ele].second=1;
	}
}*/

void dfs(int node,int par,int ct)
{
	if(arr[node]==1)
	{
		if(ct>=m)
		{
			return;
		}
		int l = v[node].size();
		int ct1=0;
		for(int i=0;i<l;i++)
		{
			if(v[node][i]!=par)
			{
				ct1++;
				dfs(v[node][i],node,ct+1);
			}
		}
		if(ct1==0)
		{
			ans++;
		}
	}
	else
	{
		int l=v[node].size(),ct1=0;
		for(int i=0;i<l;i++)
		{
			if(v[node][i]!=par)
			{
				ct1++;
				dfs(v[node][i],node,0);
			}
		}
		if(ct1==0)
		{
			ans++;
		}	
	}
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	//int n,m;
	cin >> n >> m;
	//int arr[n+1];
	for(int i=1;i<n+1;i++)
	{
		cin >> arr[i];
	}
	int x,y;
	for(int i=0;i<n-1;i++)
	{
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	/*for(int i=0;i<n+1;i++)
	{
		cat[i].first = 0;
		cat[i].second = 0;
	}*/
	dfs(1,-1,0);
	/*int ans=0;
	for(int i=1;i<n+1;i++)
	{
		cout << cat[i].first << " " << cat[i].second << endl;
		if(cat[i].first-arr[i]<=m && cat[i].second==1)
		{
			ans++;
		}
	}*/
	cout << ans;
}
