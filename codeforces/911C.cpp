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

int main(){
	int k1,k2,k3;
	scanf("%d %d %d",&k1,&k2,&k3);
	if(k1==1 || k2==1 || k3==1){
		cout << "YES" << endl;
		return 0;
	}
	if((k1==2 && k2==2)||(k2==2 && k3==2)||(k1==2 && k3==2)){
		cout << "YES" << endl;
		return 0;
	}
	if((k1==2 && k2==4 && k3==4)||(k1==4 && k2==2 && k3==4)||(k1==4 && k2==4 && k3==2)){
		cout << "YES" << endl;
		return 0;
	}
	if(k1==3 && k2==3 && k3==3){
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}