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

vector<ll> wt(1001);
vector<ll> b(1001);

vector<vector<ll> > v(1001);
vector<vector<ll> > comp(1001);

ll vis[1001]={0};
ll tot_wt[1001]={0};
ll tot_b[1001]={0};
ll ct=0,sum_wt,sum_b,w;

ll dp[1001][1001];
ll vis_1[1001][1001];
//0->none of them selected
//1->one of them selected
//2->all of them selected

void dfs(ll x){
	vis[x]=1;
	sum_wt+=wt[x];
	sum_b+=b[x];
	comp[ct].pb(x);
	for(ll i=0;i<v[x].size();i++){
		if(vis[v[x][i]]==0){
			dfs(v[x][i]);
		}
	}
}

ll calc(ll i,ll w1){
	if(w1>w){
		return INT_MIN;
	}
	if(i==ct+1){
		return 0;
	}
	if(vis_1[i][w1]==1){
		return dp[i][w1];
	}
	vis_1[i][w1]=1;
	dp[i][w1]=calc(i+1,w1);
	dp[i][w1]=max(dp[i][w1],tot_b[i]+calc(i+1,w1+tot_wt[i]));
	for(ll j=0;j<comp[i].size();j++){
		dp[i][w1]=max(dp[i][w1],b[comp[i][j]]+calc(i+1,w1+wt[comp[i][j]]));
	}
	return dp[i][w1];
}	

int main(){
	ll n,m,x,y;
	cin >> n >> m >> w;
	for(ll i=1;i<=n;i++){
		cin >> wt[i];
	}
	for(ll i=1;i<=n;i++){
		cin >> b[i];
	}
	for(ll i=0;i<m;i++){
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	for(ll i=1;i<=n;i++){
		if(vis[i]==0){
			ct++;
			sum_wt=0;
			sum_b=0;
			dfs(i);
			tot_wt[ct]=sum_wt;
			tot_b[ct]=sum_b;
		}
	}
	cout << calc(1,0) << endl;
	return 0;
}