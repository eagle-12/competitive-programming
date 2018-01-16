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
	int n,k;
	scanf("%d %d",&n,&k);
	int arr[n+1],ct[n+1];
	for(int i=0;i<=n;i++){
		ct[i]=0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		if(arr[i]==0){
			ct[i]=ct[i-1]+1;
		}
		else{
			ct[i]=ct[i-1];
		}
	}
	int l=1,r=1,len=0,a,b;
	if(ct[n]==n && k==0){
		printf("0\n");
		for(int i=0;i<n;i++){
			printf("0 ");
		}
		return 0;
	}
	while(l<=r && r<=n && l<=n){
		//cout << l << " " << r << endl;
		if(ct[r]-ct[l-1]<=k){
			r++;
		}
		else if(ct[r]-ct[l-1]>k){
			if(r-l>len){
				len=r-l;
				a=l;
				b=r-1;
			}
			l++;
		}
		if(l>r){
			r=l;
		}
	}
	if(r>n){
		r--;
	}
	//cout << l << " " << r << endl;
	if(ct[r]-ct[l-1]<=k && r-l+1>len){
		//cout << "h" << endl;
		len=r-l+1;
		a=l;
		b=r;
	}
	printf("%d\n",len);
	//cout << a << b << endl;
	for(int i=1;i<=n;i++){
		if(i>=a && i<=b){
			printf("1 ");
		}
		else{
			printf("%d ",arr[i]);
		}
	}
	return 0;
}