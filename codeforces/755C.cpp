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

int arr[10001];
int size[10001];

void initialize(int n){
	for(int i=1;i<=n;i++){
		arr[i]=i;
		size[i]=1;
	}
}

int root(int x){
	while(arr[x]!=x){
		arr[x]=arr[arr[x]];
		x=arr[x];
	}
	return x;
}

void balanced_union(int a,int b){
	int root_a=root(a);
	int root_b=root(b);
	if(size[root_a]<size[root_b]){
		arr[root_a]=arr[root_b];
		size[root_b]+=size[root_a];
	}
	else{
		arr[root_b]=arr[root_a];
		size[root_a]+=size[root_b];
	}
}

int main(){
	int n;
	cin >> n;
	int ele[n+1];
	for(int i=1;i<=n;i++){
		cin >> ele[i];
	}
	initialize(n);
	for(int i=1;i<=n;i++){
		if(i>ele[i] && ele[i]==ele[ele[i]]){
			continue;
		}
		else{
			balanced_union(i,ele[i]);
		}
	}
	int ct=0,su=0;
	for(int i=1;i<=n;i++){
		//cout << arr[i] << " ";
		if(arr[i]==i){
			ct++;
		}
	}
	//cout << endl;
	cout << ct << endl;
	return 0;
}