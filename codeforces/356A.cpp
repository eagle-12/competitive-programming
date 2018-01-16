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

int ans[300001]={0};

int main(){
	int n,m,l,r,x;
	cin >> n >> m;
	set<int> s;
	for(int i=1;i<=n;i++){
		s.insert(i);
	}
	set<int> :: iterator itr;
	for(int i=0;i<m;i++){
		cin >> l >> r >> x;
		vector<int> v;
		itr = s.lower_bound(l);
		for(;itr!=s.end();itr++){
			if(*itr>r){
				break;
			}
			if((*itr)>=l && (*itr)<=r){
				if((*itr)!=x){
					ans[*itr]=x;
					v.pb(*itr);
					//s.erase(*itr);
				}
			}

		}
		for(int j=0;j<v.size();j++){
			s.erase(v[j]);
		}
	}
	for(int i=1;i<=n;i++){
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}