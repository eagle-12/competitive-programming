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

int n,m,md,b;
int dp[501][501];
int arr[501];

int calc(int r,int c,int bug){
	if(dp[r][c]!=-1){
		return dp[r][c];
	}
}

int main(){
	int ans=0;
	scanf("%d %d %d %d",&n,&m,&b,&md);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			dp[i][j]=-1;
		}
	}
	for(int i=m;i>=0;i--){
		ans+=calc(n,m,0);
	}
	printf("%d",ans);
	return 0;
}