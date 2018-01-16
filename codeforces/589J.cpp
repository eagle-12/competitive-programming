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

int w,h,x_s,y_s;
char arr[10][10];
int depth[10][10];
int vis[10][10];

void dfs(int r,int c,int d){
	
}

int main(){
	_cin;
	cin >> w >> h;
	for(int i=0;i<w;i++){
		for(int j=0;j<h;j++){
			cin >> arr[i][j];
			depth[i][j]=0;
			if(arr[i][j]!='.' && arr[i][j]!='*'){
				x_s=i;
				y_s=j;
			}
			if(arr[i][j]=='.'){
				vis[i][j]=0;
			}
			else if(arr[i][j]=='*'){
				vis[i][j]=1;
			}
		}
	}
	dfs(x_s,y_s,1);
	return 0;
}