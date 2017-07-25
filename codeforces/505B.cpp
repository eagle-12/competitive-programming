#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define fr first
#define sc second

int vis[101] = {0};
vector<vector<pair<int,int> > > v(101);

int dfs(int x,int colour,int y)
{
	vis[x]=1;
	if(x==y)
	{
		return 1;
	}
	for(int i=0;i<v[x].size();i++)
	{
		pair<int,int> p = v[x][i];
		if(p.sc==colour && !vis[p.fr])
		{
			if(dfs(p.fr,colour,y))
			{
				return 1;
			}
		}
	}
	return 0;
}

void clear(int vis[])
{
	for(int i=0;i<101;i++)
	{
		vis[i]=0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,m,x,y,z;
	cin >> n >> m;
	pair<int,int> p;
	for(int i=0;i<m;i++)
	{
		cin >> x >> y >> z;
		p.fr = y;
		p.sc = z;
		v[x].push_back(p);
		p.fr = x;
		v[y].push_back(p);
	}
	
	int q,res;
	cin >> q;
	for(int i=0;i<q;i++)
	{
		cin >> x >> y;
		res = 0;
		for(int j=1;j<=100;j++)
		{
			clear(vis);
			
			if(dfs(x,j,y)==1)
			{
				res++;
			}
		}
		cout << res << endl;
	}
}
