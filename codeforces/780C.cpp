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

ll infi=1000000001;
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

vvi v(200001);
int vis[200001]={0};
int col[200001]={0};
int n;
set<int> s;

void dfs(int x,int par){
	vis[x]=1;
	int col1=col[x];
	int col2=col[par];
	int cl=1;
	for(int i=0;i<v[x].size();i++){
		if(vis[v[x][i]]==0){
			if(cl==col1 || cl==col2){
				cl++;
			}
			if(cl==col1 || cl==col2){
				cl++;
			}
			col[v[x][i]]=cl;
			cl++;
			dfs(v[x][i],x);
		}
	}
}

int main(){
	_cin;
	int x,y;
	cin >> n;
	for(int i=0;i<n-1;i++){
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	col[1]=1;
	dfs(1,0);
	int mx=col[1];
	for(int i=2;i<=n;i++){
		mx=max(mx,col[i]);
	}
	cout << mx << endl;
	for(int i=1;i<=n;i++){
		cout << col[i] << " ";
	}
	cout << endl;
	return 0;
}