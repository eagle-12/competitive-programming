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

vi g_1;

int main(){
	int n,x,fl=0;
	scanf("%d",&n);
	if(n%2==0){
		x=1;
		while(x<=n){
			g_1.pb(x);
			if(fl==0){
				x+=3;
				fl=1;
			}
			else{
				x+=1;
				fl=0;
			}
		}
		if(n%4==0){
			cout << 0 << endl;
		}
		else{
			cout << 1 << endl;
		}
	}
	else{
		x=1;
		while(x<=n){
			g_1.pb(x);
			x++;
			if(x<=n){
				g_1.pb(x);
			}
			x+=3;
		}
		if(n%4==1){
			cout << 1 << endl;
		}
		else{
			cout << 0 << endl;
		}
	}
	cout << g_1.size() << " ";
	for(int i=0;i<g_1.size();i++){
		cout << g_1[i] << " ";
	}
	return 0;
}