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

ii arr[100000];
int sum[100000]={0};
int n;
int a_1[100002]={0}; 
int a_2[100002]={0};

int main(){
	_cin;
	scanf("%d",&n);
	//cin >> n;
	for(int i=0;i<n;i++){
		//cin >> arr[i].fi;
		scanf("%d",&arr[i].fi);
		a_2[arr[i].fi]++;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i].se);
		//cin >> arr[i].se;
	}
	if(n==1){
		cout << 0 << endl;
		return 0;
	}
	if(n==2){
		if(arr[0].fi==arr[1].fi){
			cout << "0" << endl;
		}
		else{
			cout << min(arr[0].se,arr[1].se) << endl;
		}
		return 0;
	}
	sort(arr,arr+n);
	sum[0]=arr[0].se;
	for(int i=1;i<n;i++){
		sum[i]=sum[i-1]+arr[i].se;
	}
	int curr=-1,mn=20000001,ans;
	for(int i=0;i<n;i++){
		if(arr[i].fi==curr){
			a_1[arr[i].se]++;
		}
		else{
			int ct=a_2[arr[i].fi];
			int rem=0;
			curr=arr[i].fi;
			ans=sum[n-1]-sum[i+ct-1];
			for(int j=1;j<=200;j++){
				if(a_1[j]>0){
					if(2*ct+rem+a_1[j]<=i+ct){
						rem+=a_1[j];
						ans+=j*a_1[j];
					}
					else{
						ans+=(j*(i-ct+1-rem));
						rem=i-ct;
						break;
					}
				}
			}
			a_1[arr[i].se]++;
			mn=min(ans,mn);
		}
	}	
	printf("%lld",mn);
	return 0;
}