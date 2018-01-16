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

vector<vector<int> > v(100001);
int ini_val[100001];
int target[100001];
int vis[100001]={0};
int ct=0;
vector<int> v1;

void dfs(int x,int odd_times,int even_times,int level){
	vis[x]=1;
	int curr_val;
	if(level%2==0){
		curr_val=(ini_val[x]+even_times)%2;
		if(curr_val!=target[x]){
			ct++;
			even_times++;
			v1.pb(x);
		}
	}
	else{
		curr_val=(ini_val[x]+odd_times)%2;
		if(curr_val!=target[x]){
			ct++;
			odd_times++;
			v1.pb(x);
		}	
	}
	for(int i=0;i<v[x].size();i++){
		if(vis[v[x][i]]==0){
			//cout << v[x][i] << endl;
			dfs(v[x][i],odd_times,even_times,level+1);
		}
	}
}

int main(){
	int n,x,y;
	cin >> n;
	for(int i=0;i<n-1;i++){
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	for(int i=1;i<=n;i++){
		cin >> ini_val[i];
	}
	for(int i=1;i<=n;i++){
		cin >> target[i];
	}
	dfs(1,0,0,0);
	cout << ct << endl;
	for(int i=0;i<v1.size();i++){
		cout << v1[i] << endl;
	}
	return 0;
}