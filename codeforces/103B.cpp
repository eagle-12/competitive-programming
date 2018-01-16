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

vvi v(101);
int vis[100001]={0};

void dfs(int x){
	vis[x]=1;
	for(int i=0;i<v[x].size();i++){
		if(vis[v[x][i]]==0){
			dfs(v[x][i]);
		}
	}
}

int main(){
	_cin;
	int n,m,x,y,ct=0;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			dfs(i);
			ct++;
		}
	}
	if(ct==1 && n==m && n>=3){
		cout << "FHTAGN!" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	return 0;
}