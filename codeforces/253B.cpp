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

int arr[100000];
int ct[10001]={0};
int ans=100001;

int main(){
	_cin;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		ct[arr[i]]++;
	}
	sort(arr,arr+n);
	if(arr[n-1]<=2*arr[0]){
		cout << "0" << endl;
		return 0;
	}
	for(int i=arr[0];i<=10000;i++){
		ct[i]+=ct[i-1];
	}
	for(int i=arr[0];i<=arr[n-1];i++){
		ans=min(ans,n-(ct[2*i]-ct[i-1]));
	}
	cout << ans << endl;
	return 0;
}