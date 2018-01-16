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

int arr[100001];
int ct[100001]={0};
int dis=0,x;
int ans[100000];

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		ct[arr[i]]++;
	}
	for(int i=1;i<=100000;i++){
		if(ct[i]!=0){
			dis++;
		}
	}
	for(int i=0;i<n;i++){
		ans[i]=dis;
		ct[arr[i]]--;
		if(ct[arr[i]]==0){
			dis--;
		}
	}
	for(int i=0;i<m;i++){
		scanf("%d",&x);
		printf("%d\n",ans[x-1]);
	}
	return 0;
}