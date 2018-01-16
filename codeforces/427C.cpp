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

vector<ll> c;
vector<vector<int> > v(100001);
vector<vector<int> > rv(100001);
vector<vector<int> > comp(100001);
int vis[100001]={0};
int rvis[100001]={0};
ll n,cost=0,ways=1,val=1,id=0;
stack<int> s;

void dfs(ll x){
	vis[x]=1;
	for(ll i=0;i<v[x].size();i++){
		if(vis[v[x][i]]==0){
			dfs(v[x][i]);
		}
	}
	s.push(x);
}

void rdfs(ll x){
	rvis[x]=1;
	comp[id].pb(x);
	for(ll i=0;i<rv[x].size();i++){
		if(rvis[rv[x][i]]==0){
			rdfs(rv[x][i]);
		}
	}
}

int main(){
	ll x,idx=0,ct=0;
	scanf("%lld",&n);
	c.pb(0);
	for(ll i=0;i<n;i++){
		scanf("%lld",&x);
		c.pb(x);
	}
	ll m,y;
	cin >> m;
	for(ll i=0;i<m;i++){
		scanf("%lld %lld",&x,&y);
		v[x].pb(y);
		rv[y].pb(x);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			dfs(i);
		}
	}
	ll ele;
	while(s.size()!=0){
		ele = s.top();
		s.pop();
		if(rvis[ele]>0){
			continue;
		}
		else{
			ct++;
			rdfs(ele);
			id++;
		}
	}
	for(int i=0;i<id;i++){
		int mn=INT_MAX;
		ct=0;
		for(int j=0;j<comp[i].size();j++){
			if(c[comp[i][j]]<mn){
				mn=c[comp[i][j]];
			}
		}
		cost+=mn;
		for(int j=0;j<comp[i].size();j++){
			if(c[comp[i][j]]==mn){
				ct++;
			}
		}
		ways=((ways%mod)*(ct%mod))%mod;
	}
	cout << cost << " " << ways;
	return 0;
}