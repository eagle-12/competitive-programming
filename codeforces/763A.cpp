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
vi c(100001);
int ct=0;
int vis[100001]={0},a=-1,b=-1;
int vis_1[100001]={0};
int vis_2[100001]={0};
int fl=0;

void dfs(int x){
	vis[x]=1;
	for(int i=0;i<v[x].size();i++){
		if(vis[v[x][i]]==0){
			if(c[x]!=c[v[x][i]]){
				a=x;
				b=v[x][i];
			}
			if(a!=-1 && b!=-1){
				return;
			}
			dfs(v[x][i]);
		}
	}
}

void Dfs_a(int x,int col){
	vis_1[x]=1;
	for(int i=0;i<v[x].size();i++){
		if(vis_1[v[x][i]]==0){
			if(c[v[x][i]]!=col){
				fl=1;
				return;
			}
			if(fl==1){
				return;
			}
			Dfs_a(v[x][i],c[v[x][i]]);
		}
	}
}

void Dfs_b(int x,int col){
	vis_2[x]=1;
	for(int i=0;i<v[x].size();i++){
		if(vis_2[v[x][i]]==0){
			if(c[v[x][i]]!=col){
				fl=1;
				return;
			}
			if(fl==1){
				return;
			}
			Dfs_b(v[x][i],c[v[x][i]]);
		}
	}
}

int main(){
	_cin;
	int n,x,y;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		scanf("%d %d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	dfs(1);
	if(a==-1 && b==-1){
		cout << "YES" << endl;
		cout << "1" << endl;
		return 0;
	}
	vis_1[a]=1;
	vis_2[b]=1;
	fl=0;
	for(int i=0;i<v[a].size();i++){
		if(fl==0){
			Dfs_a(v[a][i],c[v[a][i]]);
		}
		else{
			break;
		}
	}
	if(fl==0){
		cout << "YES" << endl;
		cout << a << endl;
		return 0;
	}
	fl=0;
	for(int i=0;i<v[b].size();i++){
		if(fl==0){
			Dfs_b(v[b][i],c[v[b][i]]);
		}
		else{
			break;
		}
	}
	if(fl==0){
		cout << "YES" << endl;
		cout << b << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}