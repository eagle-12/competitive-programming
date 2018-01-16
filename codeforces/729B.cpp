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

int arr[1000][1000];
int lf[1000][1000];
int rt[1000][1000];
int dw[1000][1000];
int up[1000][1000];

int main(){
	int n,m,ans=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&arr[i][j]);
			lf[i][j]=0;
			rt[i][j]=0;
			dw[i][j]=0;
			up[i][j]=0;
		}
	}
	for(int i=n-2;i>=0;i--){
		for(int j=0;j<m;j++){
			dw[i][j]=dw[i+1][j]+arr[i+1][j];
		}
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<m;j++){
			up[i][j]=up[i-1][j]+arr[i-1][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=m-2;j>=0;j--){
			rt[i][j]=rt[i][j+1]+arr[i][j+1];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<m;j++){
			lf[i][j]=lf[i][j-1]+arr[i][j-1];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==0 && lf[i][j]>0){
				ans++;
			}
			if(arr[i][j]==0 && up[i][j]>0){
				ans++;
			}
			if(arr[i][j]==0 && rt[i][j]>0){
				ans++;
			}
			if(arr[i][j]==0 && dw[i][j]>0){
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}