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

int main(){
	int n,x,y;
	cin >> n;
	int ans[n];
	map<int,int> seq;
	map<int,int> ct;
	for(int i=1;i<=n;i++){
		cin >> x >> y;
		seq[x]=y;
		if(x!=0 && ct.find(x)==ct.end()){
			ct[x]=1;
		}
		else{
			ct[x]+=1;
		}
		if(y!=0 && ct.find(y)==ct.end()){
			ct[y]=-1;
		}
		else{
			ct[y]-=1;
		}
	}
	map <int, int> :: iterator itr;
	for(itr=ct.begin();itr!=ct.end();itr++){
		if(itr->se==1){
			ans[0]=itr->fi;
		}
		else if(itr->se==-1){
			ans[n-1]=itr->fi;
		}
	}
	int idx=1;
	while(idx<n-1){
		if(idx==1){
			ans[idx]=seq[0];
		}
		else{
			ans[idx]=seq[ans[idx-2]];
		}
		idx++;
	}
	for(int i=0;i<n;i++){
		cout << ans[i] << " ";
	}
	return 0;
}