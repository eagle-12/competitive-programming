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

int main(){
	int n,ct=0,x,ans=0;
	scanf("%d",&n);
	int id=1;
	string s;
	stack<int> st; 
	for(int i=0;i<2*n;i++){
		cin >> s;
		if(s=="add"){
			scanf("%d",&x);
			st.push(x);
		}
		else if(s=="remove"){
			if(st.size()!=0){
				if(st.top()!=id){
					ans++;
					while(st.size()!=0){
						st.pop();
					}
				}
				else{
					st.pop();
				}
			}
			id++;
		}
	}
	cout << ans << endl;
}