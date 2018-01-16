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

#define SIZE 100001
#define infi 100000000000000
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

vvi v(501);
int adj[501][501];
char arr[501];
vi a;
vi b;
vi c;

int main(){
	int n,m,x,y;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=500;i++){
		arr[i]='e';
	}
	for(int i=0;i<m;i++){
		scanf("%d %d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
		adj[x][y]=1;
		adj[y][x]=1;
	}
	for(int i=1;i<=n;i++){
		if(v[i].size()==n-1){
			arr[i]='b';
			b.pb(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(arr[i]=='e'){
			arr[i]='a';
			a.pb(i);
			for(int j=0;j<v[i].size();j++){
				if(arr[v[i][j]]=='e'){
					arr[v[i][j]]='a';
					a.pb(v[i][j]);
				}
			}
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(arr[i]=='e'){
			arr[i]='c';
			c.pb(i);
		}
	}
	//cout << a.size() << endl;
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a.size();j++){
			if(i!=j && adj[a[i]][a[j]]==0){
				printf("No");
				return 0;
			}
		}
		for(int j=0;j<b.size();j++){
			if(adj[a[i]][b[j]]==0){
				printf("No");
				return 0;
			}	
		}
		for(int j=0;j<c.size();j++){
			if(adj[a[i]][c[j]]==1){
				printf("No");
				return 0;		
			}
		}
	}
	for(int i=0;i<c.size();i++){
		for(int j=0;j<c.size();j++){
			if(i!=j && adj[c[i]][c[j]]==0){
				printf("No");
				return 0;
			}
		}
		for(int j=0;j<b.size();j++){
			if(adj[c[i]][b[j]]==0){
				printf("No");
				return 0;
			}	
		}
	}
	printf("Yes\n");
	for(int i=1;i<=n;i++){
		printf("%c",arr[i]);
	}
	return 0;
}