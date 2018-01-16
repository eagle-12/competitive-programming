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


int n,m,t,x,y,z;
int dp[5001][5001];
int path[5001][5001];
vector<vector<ii> > v(5001);
int idx;

int calc(int r,int c){
	int mn;
	if(r<=0 || c<=0){
		return 1000000001;
	}
	if(dp[r][c]!=-1){
		return dp[r][c];
	}
	dp[r][c]=1000000001;
	int ele=-1;
	for(int i=0;i<v[r].size();i++){
		mn=calc(v[r][i].fi,c-1)+v[r][i].se;
		if(mn<dp[r][c]){
			//par[r]=v[r][i].fi;
			//ele=v[r][i].fi;
			path[r][c]=v[r][i].fi;
		}
		dp[r][c]=min(dp[r][c],mn);
	}
	//cout << r << c << "h"<< endl;
	/*if(ele!=-1){
		//path[idx++]=(ele);
		par[r]=ele;
		//cout << r << c << par[r] << endl;
	}*/
	return dp[r][c];
}

int main(){
	scanf("%d %d %d",&n,&m,&t);
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&x,&y,&z);
		v[y].pb(mp(x,z));
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=-1;
		}
	}
	dp[1][1]=0;
	int i;
	for(i=n;i>=1;i--){
		if(calc(n,i)<=t){
			printf("%d\n",i);
			break;
		}
	}
	vi ans;
	ans.pb(n);
	int curr=n;
	while(curr!=1){
		curr=path[curr][i];
		ans.pb(curr);
		i--;
	}
	 
	for(int j=ans.size()-1;j>=0;j--){
		printf("%d ",ans[j]);
	}
	return 0;
}