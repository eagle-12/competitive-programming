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

char arr[16][103];
int dp[16][2];
int flr[16]={0};
int n,m;

int calc(int fl,int side){
	if(fl==n+1){
		return 0;
	}
	if(dp[fl][side]!=-1){
		//cout << "h";
		return dp[fl][side];
	}
	if(flr[fl]==0){
		dp[fl][side]=1+calc(fl+1,side);
		//cout << "h";
		return dp[fl][side];
	}
	int rh=0,lf=m+1;
	for(int i=1;i<m+1;i++){
		if(arr[fl][i]=='1'){
			rh=i;
		}
	}
	for(int i=m;i>0;i--){
		if(arr[fl][i]=='1'){
			lf=i;
		}
	}
	if(fl==n){
		//cout << rh << lf << endl;
		if(side==0){
			dp[fl][side]=rh;
		}
		else{
			dp[fl][side]=m+1-lf;
		}
		return dp[fl][side];
	}
	else if(fl==0){
		dp[fl][side]=min(2*rh+1+calc(fl+1,0),m+2+calc(fl+1,1));
		return dp[fl][side];
	}
	else{
		if(side==0){
			dp[fl][side]=min(2*rh+1+calc(fl+1,0),m+2+calc(fl+1,1));
		}
		else{
			dp[fl][side]=min(m+2+calc(fl+1,0),2*(m+1-lf)+1+calc(fl+1,1));
		}
		return dp[fl][side];
	}
}

int main(){
	_cin;
	cin >> n >> m;
	int x=n;
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<m+2;j++){
			cin >> arr[i][j];
			flr[i]+=arr[i][j]-'0';
		}
		dp[i][0]=-1;
		dp[i][1]=-1;
	}
	n=0;
	for(int i=0;i<x;i++){
		if(flr[i]!=0){
			n=i;
		}
	}
	if(n==0 && flr[0]==0){
		cout << 0 << endl;
		return 0;
	}
	cout << calc(0,0) << endl;
	return 0;
}