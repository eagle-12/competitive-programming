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

vvi v(100001);
int col[100001]={0};
int dp[100001]={0};
int vis[100001]={0};

void dfs(int x){
	vis[x]=1;
	dp[x]=col[x];
	for(int i=0;i<v[x].size();i++){
		if(vis[v[x][i]]==0){
			dfs(v[x][i]);
			dp[x]+=dp[v[x][i]];
		}
	}
}

int main(){
	int n,x,y,z;
	cin >> n;
	for(int i=0;i<n-1;i++){
		cin >> x >> y >> z;
		v[x].pb(y);
		v[y].pb(x);
		if(z==2){
			col[x]=1;
			col[y]=1;
		}
	}
	dfs(1);
	vi v1;
	for(int i=1;i<=n;i++){
		if(dp[i]==1){
			v1.pb(i);
		}
	}
	cout << v1.size() << endl;
	for(int i=0;i<v1.size();i++){
		cout << v1[i] << " ";
	}
	return 0;
}