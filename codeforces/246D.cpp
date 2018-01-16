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

int c[100001]={0};
set<int> v[100005];
int p[100001]={0};
int ans=INT_MAX;

int main(){
	int n,m,x,y,idx=0;;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> c[i];
		ans=min(ans,c[i]);
	}
	for(int i=0;i<m;i++){
		cin >> x >> y;
		if(c[x]!=c[y]){
			v[c[x]].insert(c[y]);
			v[c[y]].insert(c[x]);
		}
	}
	for (int i = 1; i < 100005; i++){
		if (v[ans].size() < v[i].size()){
			ans = i;
		}
	}
	cout << ans;
}