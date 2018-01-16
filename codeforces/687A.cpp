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

int vis[100001]={0};
int col[100001];
vector<vector<int> > v(100001);
vector<int> c0;
vector<int> c1;

void dfs(int x,int colour){
	if(colour==0){
		c1.pb(x);
	}
	else{
		c0.pb(x);
	}
	vis[x]=1;
	for(int i=0;i<v[x].size();i++){
		if(vis[v[x][i]]==0){
			if(col[v[x][i]]==-1){
				col[v[x][i]]=colour;
			}
			else{
				if(col[v[x][i]]!=colour){
					cout << "-1" << endl;
					exit(0);
				}
			}
			int c=1;
			if(colour==1){
				c=0;
			}
			dfs(v[x][i],c);
		}
		else{
			if(col[x]==col[v[x][i]]){
				cout << "-1" << endl;
				exit(0);
			}
		}
	}
}

int main(){
	int n,m,x,y;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		col[i]=-1;
	}
	for(int i=0;i<m;i++){
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0 && v[i].size()!=0){
			col[i]=0;
			dfs(i,1);
		}
	}
	cout << c0.size() << endl;
	for(int i=0;i<c0.size();i++){
		cout << c0[i]  << " ";
	}
	cout << endl;
	cout << c1.size() << endl;
	for(int i=0;i<c1.size();i++){
		cout << c1[i] << " " << endl;
	}
	return 0;
}