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

vector<vector<int> > v(50001);

int level[50001]={0};
int vis[50001]={0};

int dis[50001][501];
int ans=0,n,k;

void dfs(int node){
	vis[node]=1;
	dis[node][0]=1;
	for(int i=0;i<v[node].size();i++){
		if(vis[v[node][i]]==0){
			dfs(v[node][i]);
			for(int j=0;j<k;j++){
				ans+=dis[node][j]*dis[v[node][i]][k-1-j];
			}
			for(int j=0;j<k;j++){
				dis[node][j+1]+=dis[v[node][i]][j];
			}
		}
	}
}

int main()
{
	int x,y;
	cin >> n >> k;
	for(int i=0;i<n-1;i++)
	{
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}
