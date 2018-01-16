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

int ct_a[5002]={0};
int ct_b[5002]={0};

int main(){
	string s;
	cin >> s;
	int ans=0,x;
	for(int i=0;i<s.size();i++){
		if(s[i]=='a'){
			ct_a[i+1]++;
		}
		else{
			ct_b[i+1]++;
		}
	}
	for(int i=2;i<=s.size();i++){
		ct_a[i]+=ct_a[i-1];
		ct_b[i]+=ct_b[i-1];
	}
	//cout << endl;
	int l=s.size();
	for(int i=0;i<=l;i++){
		for(int j=i;j<=l+1;j++){
			if(j==i){
				ans=max(ans,ct_a[l]);
			}
			else if(j==l+1){
				ans=max(ans,ct_a[i]+ct_b[l]-ct_b[i]);
			}
			else{
				ans=max(ans,ct_a[i]+ct_b[j-1]-ct_b[i]+ct_a[l]-ct_a[j-1]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}