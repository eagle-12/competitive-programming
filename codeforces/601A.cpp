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

int arr[401][401];
vvi v(401);
int vis[401]={0};
int len[401]={0};

int main(){
	int n,m,x,y,fl=1;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&x,&y);
		arr[x][y]=1;
		arr[y][x]=1;
	}
	if(arr[1][n]==1){
		fl=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(arr[i][j]==fl && j!=i){
				v[i].pb(j);
			}
		}
	}
	int curr;
	queue<int> q;
	q.push(1);
	vis[1]=1;
	len[1]=0;
	while(q.size()!=0){
		curr=q.front();
		q.pop();
		for(int i=0;i<v[curr].size();i++){
			if(vis[v[curr][i]]==0){
				vis[v[curr][i]]=1;
				q.push(v[curr][i]);
				len[v[curr][i]]=len[curr]+1;
			}
		}
	}
	if(len[n]==0){
		cout << "-1" << endl;
	}
	else{
		cout << max(len[n],1) << endl;
	}
	return 0;
}