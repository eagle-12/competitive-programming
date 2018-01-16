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

vector<pair<ll,ll> > v(100000);

int main(){
	_cin;
	ll n,r,avg;
	cin >> n >> r >> avg;
	ll req,curr=0,ans=0;
	req=n*avg;
	for(ll i=0;i<n;i++){
		cin >> v[i].se >> v[i].fi;
		curr+=v[i].se;
	}
	if(curr>=req){
		cout << 0 << endl;
		return 0;
	}
	sort(v.begin(),v.begin()+n);
	for(ll i=0;i<v.size();i++){
		if(curr<req){
			if((curr+r-v[i].se)<=req){
				ans+=v[i].fi*(r-v[i].se);
				curr+=r-v[i].se;
			}
			else if((curr+r-v[i].se)>req){
				ans+=v[i].fi*(req-curr);
				curr=req;
			}
		}
		if(curr==req){
			cout << ans << endl;
			return 0;
		}
	}
	return 0;
}