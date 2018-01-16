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

vl v(5001);
vl sum(5001);

ll dp[5001][5001];

ll calc(ll start,ll m,ll k,ll n){
	if(start>n || k==0){
		return 0;
	}
	if(dp[start][k]!=-1){
		return dp[start][k];
	}
	ll r=start+m-1;
	if(r<=n){
		dp[start][k]=max(sum[r]-sum[start-1]+calc(start+m,m,k-1,n),dp[start][k]);
	}
	dp[start][k]=max(dp[start][k],calc(start+1,m,k,n));
	return dp[start][k];
}

int main(){
	_cin;
	ll n,m,k;
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		cin >> v[i];
	}
	for(int i=0;i<=5000;i++){
		for(int j=0;j<=5000;j++){
			dp[i][j]=-1;
		}
	}
	sum[0]=0;
	sum[1]=v[1];
	for(int i=2;i<=n;i++){
		sum[i]=v[i]+sum[i-1];
		//cout << sum[i];
	}
	cout << calc(1,m,k,n) << endl;
	return 0;
}