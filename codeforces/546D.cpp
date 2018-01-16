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

ll prime_div[5000001];
int prime[5000001];
ll prime_div_num[5000001];

int main(){
	ll x;
	for(ll i=2;i<=5000000;i++){
		prime[i]=1;
		prime_div_num[i]=0;
	}
	for(ll i=2;i*i<=5000000;i++){
		if(prime[i]==1){
			for(ll j=2*i;j<=5000000;j+=i){
				prime[j]=0;
				prime_div[j]=i;
			}
		}
	}
	for(ll i=2;i<=5000000;i++){
		if(prime[i]==1){
			prime_div_num[i]=1;
		}
	}
	for(ll i=2;i<=5000000;i++){
		if(prime_div_num[i]==0){
			x=i/prime_div[i];
			prime_div_num[i]=1+prime_div_num[x];
		}
	}
	//cout << prime_div_num[2];
	for(ll i=3;i<=5000000;i++){
		//cout << prime_div[i] << " ";
		prime_div_num[i]+=prime_div_num[i-1];
	}
	//cout << prime_div_num[4];
	ll t,a,b;
	scanf("%lld",&t);
	for(ll i=0;i<t;i++){
		scanf("%lld %lld",&a,&b);
		printf("%lld\n",prime_div_num[a]-prime_div_num[b]);
	}
	
	return 0;
}