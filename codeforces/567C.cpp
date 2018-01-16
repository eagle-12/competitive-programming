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

vl v1(200001);
ll ans[200001]={0};

map<ll,vl> m;

ll find_b(ll ele,ll idx){
	if(m.find(ele)==m.end()){
		//cout << "HELLO";
		return -1;
	}
	ll low=0;
	ll high=m[ele].size()-1;
	//cout << low << high << endl;
	//cout << m[ele][0] << m[ele][1] << m[ele][2] << endl;
	while(low<=high){
		ll mid=(low+high)/2;
		//cout << "mid" << mid<<  endl;
		if(m[ele][mid]<idx && (mid==m[ele].size()-1 || (mid+1<=m[ele].size()-1 && m[ele][mid+1]>=idx))){
			return (mid+1);
		}
		else if(m[ele][mid]<idx){
			//cout << "mid__" ;
			low=mid+1;
		}
		else if(m[ele][mid]>=idx){
			high=mid-1;
			//cout << high << "h" << endl;
		}
	}
	return -1;
}

ll find_a(ll ele,ll idx){
	if(m.find(ele)==m.end()){
		return -1;
	}
	ll low=0;
	ll high=m[ele].size()-1;
	//cout << high;
	while(low<=high){
		ll mid=(low+high)/2;
		if(m[ele][mid]>idx && (mid==0 ||(mid-1>=0 && m[ele][mid-1]<=idx))){
			return m[ele].size()-mid;
		}
		else if(m[ele][mid]>idx){
			high=mid-1;
		}
		else if(m[ele][mid]<=idx){
			low=mid+1;
		}
	}
	return -1;
}

int main(){
	_cin;
	ll n,k;
	cin >> n >> k;
	for(ll i=1;i<=n;i++){
		cin >> v1[i];
		if(m.find(v1[i])==m.end()){
			vl v;
			v.pb(i);
			m[v1[i]]=v;
		}
		else{
			m[v1[i]].pb(i);
		}
	}
	//cout << find_b(1,2) << endl;
	for(ll i=2;i<n;i++){
		if(v1[i]%k==0){
			ll a=find_b(v1[i]/k,i);
			ll b=find_a(v1[i]*k,i);
			//cout << a << b << endl;
			if(a!=-1 && b!=-1){
				ans[i]=a*b;
			}
		}
	}
	ll sum=0;
	for(ll i=1;i<=n;i++){
		sum+=ans[i];
	}
	cout << sum << endl;
	return 0;
}