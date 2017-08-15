#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back


using namespace std;

vector<vector<int> > v(100001);

int visited[100001]={0};

double ans[100001]={0};

void dfs(int ele)
{
	visited[ele]=1;
	int ct=0;
	for(int i=0;i<v[ele].size();i++)
	{
		if(visited[v[ele][i]]==0)
		{
			dfs(v[ele][i]);
			ans[ele]+=ans[v[ele][i]]+1;
			ct++;
		}
	}
	if(ct!=0)
	{
		ans[ele]/=ct;
	}
}

int main()
{
	int n;
	cin >> n;
	int x,y;
	for(int i=1;i<n;i++)
	{
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1);
	//cout << ans[1] << endl;
	//printf("%.lf",ans[1]);
	printf("%.9lf\n",ans[1]);
	
}
