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

ll inf=100000000001;

vi c(101);
int lt[101][101];
ll dp[101][101][101];
ll n,m,k;

void calc(){
	if(c[1]==0){
		for(int i=1;i<=m;i++){
			dp[1][1][i]=lt[1][i];
		}
	}
	else{
		dp[1][1][c[1]]=0;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(c[i]==0){
				for(int a=1;a<=m;a++){
					dp[i][j][a]=min(dp[i][j][a],dp[i-1][j][a]+lt[i][a]);
				}
				for(int a=1;a<=m;a++){
					for(int b=1;b<=m;b++){
						if(a!=b){
							dp[i][j][a]=min(dp[i][j][a],dp[i-1][j-1][b]+lt[i][a]);
						}
					}
				}
			}
			else{
				dp[i][j][c[i]]=min(dp[i-1][j][c[i]],dp[i][j][c[i]]);
 				// selecting the colour of the previous tree
 				for(int a=1;a<=m;a++){
 					if(a!=c[i]){
						dp[i][j][c[i]]=min(dp[i][j][c[i]],dp[i-1][j-1][a]);
 					}
				}
			}
		}
	}
	ll ans=inf;
	for(int i=1;i<=m;i++){
		ans=min(ans,dp[n][k][i]);
	}
	if(ans==inf){
		cout << "-1" << endl;
	}
	else{
		cout << ans << endl;
	}
}

int main(){
	_cin;
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> lt[i][j];
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=k;j++){
			for(int x=0;x<=m;x++){
				dp[i][j][x]=inf;
			}
		}
	}
	//cout << dp[1][1][2] << endl;
	calc();
	return 0;
}