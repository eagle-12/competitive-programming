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

ll dis[SIZE];
int vis[SIZE]={0};
vector<pair<int,int> > v[SIZE];
int pre[SIZE];
vi path;

int main(){
	int n,m,x,y,z,a,b;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&x,&y,&z);
		v[x].pb(mp(y,z));
		v[y].pb(mp(x,z));
	}
	for(int i=0;i<=n;i++){
		dis[i]=infi;
	}
	dis[1]=0;
	multiset<ii> s;
	s.insert(mp(0,1));
	while(!s.empty()){
		ii p=*s.begin();
		s.erase(s.begin());
		a=p.se;
		b=p.fi;
		if(vis[a]==1){
			continue;
		}
		vis[a]=1;
		for(int i=0;i<v[a].size();i++){
			int e=v[a][i].fi;
			int w=v[a][i].se;
			if(dis[a]+w<dis[e]){
				dis[e]=dis[a]+w;
				pre[e]=a;
				s.insert(mp(dis[e],e));
			}
		}
	}
	if(dis[n]==infi){
		cout << "-1" << endl;
		return 0;
	}
	else{
		int curr=n;
		path.pb(n);
		while(curr!=1){
			path.pb(pre[curr]);
			curr=pre[curr];
		}
		for(int i=path.size()-1;i>=0;i--){
			printf("%d ",path[i]);
		}
	}
	return 0;
}