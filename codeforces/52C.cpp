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

ll infi=1000000001;
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

ll arr[200001];
ll tree[1000004];
ll lazy[1000004]={0};

void build(ll node,ll start,ll end){
	if(start==end){
		tree[node]=arr[start];
	}
	else{
		ll mid=(start+end)/2;
		build(2*node+1,start,mid);
		build(2*node+2,mid+1,end);
		tree[node]=min(tree[2*node+1],tree[2*node+2]);
	}
}

void update_lazy(ll node,ll start,ll end,ll l,ll r,ll diff){
	if(lazy[node]!=0){
		tree[node]+=lazy[node];
		if(start!=end){
			lazy[2*node+1]+=lazy[node];
			lazy[2*node+2]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(start>end || start>r || end<l){
		return;
	}
	if(start>=l && end<=r){
		tree[node]+=diff;
		if(start!=end){
			lazy[2*node+1]+=diff;
			lazy[2*node+2]+=diff;
		}
		return;
	}
	ll mid=(start+end)/2;
	update_lazy(2*node+1,start,mid,l,r,diff);
	update_lazy(2*node+2,mid+1,end,l,r,diff);
	tree[node]=min(tree[2*node+1],tree[2*node+2]);
}

ll query(ll node,ll start,ll end,ll l,ll r){
	if(start>end || start>r || end<l){
		return infi;
	}
	if(lazy[node]!=0){
		tree[node]+=lazy[node];
		if(start!=end){
			lazy[2*node+1]+=lazy[node];
			lazy[2*node+2]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(start>=l && end<=r){
		return tree[node];
	}
	ll mid=(start+end)/2;
	ll p1=query(2*node+1,start,mid,l,r);
	ll p2=query(2*node+2,mid+1,end,l,r);
	return min(p1,p2);
}

int main(){
	ll n,m,l,r,diff,num1,num2;
	char ch;
	scanf("%lld",&n);
	for(ll i=0;i<n;i++){
		scanf("%lld",&arr[i]);
	}
	build(0,0,n-1);
	scanf("%lld",&m);
	while(m--){
		scanf("%lld %lld%c",&l,&r,&ch);
		if(ch!='\n'){
			scanf("%lld",&diff);
			if(l>r){
				update_lazy(0,0,n-1,l,n-1,diff);
				update_lazy(0,0,n-1,0,r,diff);
			}
			else{
				update_lazy(0,0,n-1,l,r,diff);
			}
		}
		else{
			if(l>r){
				num1=query(0,0,n-1,l,n-1);
				num2=query(0,0,n-1,0,r);
				printf("%lld\n",min(num1,num2));
			}
			else{
				num1=query(0,0,n-1,l,r);
				printf("%lld\n",num1);
			}
		}
	}
	return 0;
}