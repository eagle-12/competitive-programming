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

vector<vector<ll> > v(100001);
ll vis[100001]={0};
ll mn;
ll c[100001];

void dfs(ll x){
	vis[x]=1;
	if(c[x]<mn){
		mn=c[x];
	}
	for(ll i=0;i<v[x].size();i++){
		if(vis[v[x][i]]==0){
			dfs(v[x][i]);
		}
	}
}

int main(){
	ll n,m,ans=0,x,y;
	cin >> n >> m;
	for(ll i=1;i<=n;i++){
		cin >> c[i];
	}
	for(ll i=0;i<m;i++){
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	for(ll i=1;i<=n;i++)
	{
		if(vis[i]==0){
			mn=c[i];
			dfs(i);
			ans+=mn;
		}
	}
	cout << ans;
	return 0;
}