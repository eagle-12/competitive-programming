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
	string s,s1,ans;
	cin >> s >> s1;
	ans+=s[0];
	for(int i=1;i<s.size();i++){
		if(s[i]<s1[0]){
			ans+=s[i];
		}
		else if(s[i]>=s1[0]){
			break;
		}
	}
	ans+=s1[0];
	cout << ans << endl;
	return 0;
}