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

ll infi=1000000001;
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

int w[200000]={0};
vii v(200000);

int main(){
	_cin;
	int n,w1;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> w[i] >> v[i].fi;
		v[i].se=i;
		if(i>0){
			w[i]+=w[i-1];
		}
	}
	sort(v.begin(),v.begin()+n);
	int mx=v[n-1].fi;
	int idx1=v[n-1].se;
	int mx1=v[n-2].fi;
	int idx2=v[n-2].se;
	for(int i=0;i<n;i++){
		if(i==0){
			w1=w[n-1]-w[0];
		}
		else if(i!=n-1){
			w1=w[i-1]+w[n-1]-w[i];
		}
		else{
			w1=w[n-2];
		}
		if(i==idx1){
			cout << mx1*w1 << " ";
		}
		else{
			cout << mx*w1 << " ";
		}
	}
	return 0;
}