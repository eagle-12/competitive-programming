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

int dp[11][101][101];

int main(){
	int n,q,c,x,y,z;
	cin >> n >> q >> c;
	for(int i=0;i<n;i++){
		cin >> x >> y >> z;
		dp[z][x][y]++;
	}
	for(int p=0;p<=c;p++){
		for(int i=1;i<101;i++){
			for(int j=1;j<101;j++){
				dp[p][i][j]+=dp[p][i-1][j]+dp[p][i][j-1]-dp[p][i-1][j-1];
			}
		}
	}
	int t,x1,x2,y1,y2,ans=0;
	for(int i=0;i<q;i++){
		cin >> t >> x1 >> y1 >> x2 >> y2;
		ans=0;
		for(int p=0;p<=c;p++){
			int final_b=(p+t)%(c+1);
			ans+=(final_b)*(dp[p][x2][y2]-dp[p][x1-1][y2]-dp[p][x2][y1-1]+dp[p][x1-1][y1-1]);
		}
		cout << ans << endl;
	}

	return 0;
}