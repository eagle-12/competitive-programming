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

typedef pair<int, int> ii;
typedef pair<ll, ll> II;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<ii> vii;
typedef vector<vii> vvii;

ll n;
ll arr[100001];
vector<vector<ii> > v(100001);
int vis[100001]={0};
ll num[100001]={0};
ll visited[100001]={0};
ll ans=0;

ll calc(ll x){
	vis[x]=1;
	for(int i=0;i<v[x].size();i++){
		if(vis[v[x][i].fi]==0){
			num[x]+=1+calc(v[x][i].fi);
		}
	}
	return num[x];
}

void dfs(ll x,ll dis,ll mn){
	visited[x]=1;
	if(dis-mn>arr[x]){
		ans+=1+num[x];
		//cout << x << endl;
		return;
	}
	for(ll i=0;i<v[x].size();i++){
		if(visited[v[x][i].fi]==0){
			if(dis+v[x][i].se<mn){
				//mn=dis+v[x][i].se;
				dfs(v[x][i].fi,dis+v[x][i].se,dis+v[x][i].se);
			}
			else{
				dfs(v[x][i].fi,dis+v[x][i].se,mn);
			}
		}
	}
}

int main(){
	ll x,y;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&arr[i]);
	}
	for(ll i=1;i<=n-1;i++){
		scanf("%lld %lld",&x,&y);
		v[i+1].pb(mp(x,y));
		v[x].pb(mp(i+1,y));
	}
	calc(1);
	dfs(1,0,0);
	printf("%lld",ans);
	return 0;
}