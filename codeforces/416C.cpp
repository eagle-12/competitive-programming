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

pair<pair<int,int>,int > arr[1000];
pair<int,int> cap[1000];
vii v;
int cov[1000]={0};

int main(){
	int n,k,x,ct=0,ans=0,y;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&arr[i].fi.se,&arr[i].fi.fi);
		arr[i].se=i+1;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&cap[i].fi);
		cap[i].se=i+1;
	}
	//cout << arr[0].fi.se << arr[0].se<< endl;
	sort(arr,arr+n);
	sort(cap,cap+k);
	//cout << arr[0].fi.se << arr[0].se<< endl;
	//cout << arr[y].fi.se << " " << cap[x].fi << endl;
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<k;j++){
			if(cov[j]==0 && cap[j].fi>=arr[i].fi.se){
				cov[j]=1;
				ct++;
				ans+=arr[i].fi.fi;
				v.pb(mp(arr[i].se,cap[j].se));
				break;
			}
		}
	}
	printf("%d %d\n",ct,ans);
	for(int i=0;i<v.size();i++){
		printf("%d %d\n",v[i].fi,v[i].se);
	}
	return 0;
}