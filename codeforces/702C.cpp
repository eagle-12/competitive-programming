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

int a[SIZE];
int b[SIZE];
int n,m;

int binary_search(int l,int r,int key){
	int low=l;
	int high=r;
	while(low<=high){
		int mid=(low+high)/2;
		if(mid==0 && b[mid]>key){
			return mid;
		}
		else if(b[mid]<=key && (mid==m-1 || (mid<n-1 && b[mid+1]>key))){
			return mid;
		}
		else if(b[mid]>key){
			high=mid-1;
		}
		else if(b[mid]<key){
			low=mid+1;
		}
	}
}

int main(){
	_cin;
	int ans;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<m;i++){
		cin >> b[i];
	}
	int idx=binary_search(0,m-1,a[0]);
	if(idx!=m-1){
		ans=min(abs(b[idx]-a[0]),abs(b[idx+1]-a[0]));
	}
	else{
		ans=abs(b[idx]-a[0]);
	}
	//cout << idx << endl;
	for(int i=1;i<n;i++){
		if(a[i]>=b[idx] && ((idx!=m-1 && b[idx+1]>=a[i]))||(idx==m-1)){
			idx=idx;
		}
		else{
			idx=binary_search(idx+1,m-1,a[i]);
		}
			//cout << idx << endl;
		if(idx!=m-1){
			ans=max(ans,min(abs(b[idx]-a[i]),abs(b[idx+1]-a[i])));
		}
		else{
			ans=max(ans,abs(b[idx]-a[i]));
		}
	}
	cout << ans << endl;
	return 0;
}