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

int col[200001];
vector<vector<int> > v(200001);
vector<vector<int> > comp(200001);
int idx=0,ans=0;
int vis[200001]={0};

void dfs(int x){
	vis[x]=1;
	comp[idx].pb(col[x]);
	for(int i=0;i<v[x].size();i++){
		if(vis[v[x][i]]==0){
			dfs(v[x][i]);
		}
	}
}

int main(){
	int n,m,k,l,r;
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		cin >> col[i];
	}
	for(int i=0;i<m;i++){
		cin >> l >> r;
		v[l].pb(r);
		v[r].pb(l);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			dfs(i);
			idx++;
		}
	}
	for(int i=0;i<idx;i++){
		map<int,int> m;
		map<int,int> :: iterator itr;
		for(int j=0;j<comp[i].size();j++){
			if(m.find(comp[i][j])==m.end()){
				m[comp[i][j]]=1;
			}
			else{
				m[comp[i][j]]+=1;	
			}
		}
		int mx=-1;
		for(itr=m.begin();itr!=m.end();itr++){
			mx=max(itr->se,mx);
		}
		ans+=(comp[i].size()-mx);
	}
	cout << ans << endl;
	return 0;
}