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

int ele[100001];
int des[100001];
int q[100001];
int ndes[100001];
int arr[100001];
int size[100001];
ll sum[100001];
int r;
ll s=0;

vector<ll> ans;

void initialize(int n){
	for(int i=1;i<=n;i++){
		arr[i]=i;
		size[i]=1;
	}
}

int root(int i){
	while(arr[i]!=i){
		arr[i]=arr[arr[i]];
		i=arr[i];
	}
	return i;
}

void balanced_union(int a,int b){
	ll root_a=root(a);
	int root_b=root(b);
	if(size[root_a]<size[root_b]){
		arr[root_a]=arr[root_b];
		size[root_b]+=size[root_a];
		sum[root_b]+=sum[root_a];
		r=root_b;
	}
	else{
		arr[root_b]=arr[root_a];
		size[root_a]+=size[root_b];
		sum[root_a]+=sum[root_b];
		r=root_a;
	}
}

int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> ele[i];
		ndes[i]=0;
		sum[i]=ele[i];
	}
	for(int i=1;i<=n;i++){
		cin >> des[i];
	}
	initialize(n);
	ans.pb(0);
	r=des[n];
	int fl=0;
	for(int i=n;i>=1;i--){
		ndes[des[i]]=1;
		fl=0;
		if(des[i]==n && ndes[n-1]==1){
			balanced_union(n,n-1);
			fl=1;
		}
		else if(des[i]==1 && ndes[2]==1){
			balanced_union(1,2);
			fl=1;
		}
		else if(ndes[des[i]-1]==1 || ndes[des[i]+1]==1){
			if(ndes[des[i]-1]==1 && ndes[des[i]+1]==1){
				balanced_union(des[i],des[i]-1);
				balanced_union(des[i],des[i]+1);
			}
			else if(ndes[des[i]-1]==1){
				balanced_union(des[i],des[i]-1);
			}
			else{
				balanced_union(des[i],des[i]+1);
			}
			fl=1;
		}
		/*cout << "sum" << " ";
		for(int j=1;j<=n;j++){
			cout << sum[j] << " ";
		}
		cout << " fl" << fl;*/
		//cout << endl;
		if(fl==0){
			r=des[i];
		}
		s=max(s,sum[r]);
		//cout << " " <<  s << endl;
		ans.pb(s);
	}
	for(int i=ans.size()-2;i>=0;i--){
		cout << ans[i] << endl;
	}
	return 0;
}