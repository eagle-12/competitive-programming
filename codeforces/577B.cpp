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

int n,m;
int arr[1000000]={0};
int dp[1000][1000];

void calc(int i,int sum,int ct){
	if(i>=n){
		return ;
	}
	/*if(i==2 && sum==1 && ct==1){
		cout << "hello" << endl;
		cout << (sum+(arr[i]%m))%m << endl;
		cout << dp[i][0] << endl;
	}*/
	if(dp[i][(sum+(arr[i]%m))%m]!=-1 && (ct>=1 && dp[i][sum]!=-1)){
		return;
	}
	if(sum==0 && ct>=1){
		cout << "YES" << endl;
		exit(0);
	}
	dp[i][(sum+(arr[i]%m))%m]=1;
	if(ct>=1){
		dp[i][sum]=1;
	}
	/*if(i==1 && sum==0){
		cout << sum << " sum" << endl;
		cout << ct << " ct" << endl;
		cout << (sum+(arr[i]%m))%m << endl;	
		cout << dp[n-1][0] << endl;
	}*/
	calc(i+1,(sum+(arr[i]%m))%m,ct+1);
	calc(i+1,sum,ct);
}

int main(){
	_cin;
	int x;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	if(n>m){
		cout << "YES" << endl;
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dp[i][j]=-1;
		}
	}
	calc(0,0,0);
	//cout << dp[n-1][0] << endl;
	/*for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	if(dp[n-1][0]==1){
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}