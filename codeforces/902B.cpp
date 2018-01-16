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

vector<vector<int> > v(10001);
vector<int> c(10001);
int vis[10001]={0};
int ct=0;

void dfs(int x,int curr){
	vis[x]=1;
	int fl=0;
	if(curr!=c[x]){
		ct++;
		fl=1;
	}
	for(int i=0;i<v[x].size();i++){
		if(vis[v[x][i]]==0){
			if(fl==1){
				dfs(v[x][i],c[x]);
			}
			else{
				dfs(v[x][i],curr);
			}
		}
	}
}

int main(){
	int n,x,idx=2;
	cin >> n;
	for(int i=1;i<n;i++){
		cin >> x;
		v[idx].pb(x);
		v[x].pb(idx);
		idx++;
	}
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	//cout << v[2][0] << " " << v[2][1] << " " << v[2][2] <<  endl;
	dfs(1,0);
	cout << ct << endl;
	return 0;
}