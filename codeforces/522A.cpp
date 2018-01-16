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

vvi v(500);
int height[500]={0};
int vis[500]={0};

void dfs(int x){
	vis[x]=1;
	int ct=0;
	for(int i=0;i<v[x].size();i++){
		if(vis[v[x][i]]==0){
			dfs(v[x][i]);
			ct++;
			height[x]=max(height[x],1+height[v[x][i]]);
		}
	}
	if(ct==0){
		height[x]=1;
	}
}

int main(){
	int n;
	scanf("%d",&n);
	string s,s1,s2;
	map<string,int> m;
	m["polycarp"]=1;
	int mx=2;
	for(int i=0;i<n;i++){
		cin >> s >> s1 >> s2;
		transform(s.begin(),s.end(),s.begin(),::tolower);
		transform(s2.begin(),s2.end(),s2.begin(),::tolower);
		if(m.find(s)==m.end()){
			m[s]=mx;
			mx++;
		}
		if(m.find(s2)==m.end()){
			m[s2]=mx;
			mx++;
		}
		v[m[s]].pb(m[s2]);
		v[m[s2]].pb(m[s]);
	}
	dfs(1);
	cout << height[1] << endl;
	return 0;
}