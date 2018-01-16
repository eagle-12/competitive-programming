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

int main(){
	_cin;
	int n,d,h;
	cin >> n >> d >> h;
	if(d-h>h || n<=h || (d==1 && h==1 && n>=3)){
		cout << "-1" << endl;
		return 0;
	}
	int ct=0,curr=2,ver=1;
	while(ct<h && curr<=n){
		cout << ver << " " << curr << endl;
 		ver=curr;
		curr++;
		ct++;
	}
	int x=d-h;
	if(x==0){
		int prev=2;
		while(curr<=n){
			cout << prev << " " << curr << endl;
			curr++;
		}
		return 0;
	}
	ct=0;
	int prev=1;
	while(ct<=x && curr<=n){
		cout << prev << " " << curr << endl;
		prev=curr;
		curr++;
		ct++;
		if(ct==x){
			prev=1;
			ct=0;
		}
	}
	return 0;
}