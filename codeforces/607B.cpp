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

int arr[501];
int dp[501][501];
int n;

int calc(int i,int j){
	if(i==j){
		dp[i][j]=1;
		return dp[i][j];
	}
	else if(i>j){
		dp[i][j]=0;
		return dp[i][j];
	}
	if(dp[i][j]!=100000000){
		return dp[i][j];
	}
	else{
		//cout << "hell";
			dp[i][j]=min(dp[i][j],1+calc(i+1,j));
			if(arr[i+1]==arr[i]){
				dp[i][j]=min(dp[i][j],1+calc(i+2,j));
			}
			for(int k=i+2;k<=j;k++){
				//cout << "loo" << endl;
				if(arr[k]==arr[i]){
					//cout << i+1 << endl;
					//cout << "n=" << n << endl;
					//cout << "loop" << endl;
					//printf("%d\n",calc(i+1,k-1)+calc(k+1,j));
					dp[i][j]=min(dp[i][j],calc(i+1,k-1)+calc(k+1,j));
				}
			}
		return dp[i][j];
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dp[i][j]=100000000;
		}
	}
	int ans=calc(0,n-1);
	printf("%d",ans);
	return 0;
}