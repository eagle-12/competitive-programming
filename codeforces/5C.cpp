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

int len[1000000];
int idx[1000000];

int main(){
	string s;
	cin >> s;
	int ct=0,ct1=0;
	stack<int> st;
	for(int i=0;i<s.size();i++){
		len[i]=-1;
		idx[i]=-1;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='('){
			st.push(i);
		}
		else if(s[i]==')'){
			if(st.size()!=0){
				idx[i]=st.top();
				st.pop();
				len[i]=i-idx[i]+1;
				//cout << len[i] << endl;
				if(idx[i]>0 && s[idx[i]-1]==')' && len[idx[i]-1]!=-1){
					len[i]+=len[idx[i]-1];
				}
			}
		}
	}
	int mx=len[0];
	for(int i=1;i<s.size();i++){
		mx=max(mx,len[i]);
	}
	for(int i=0;i<s.size();i++){
		if(len[i]==mx){
			ct++;
		}
	}
	if(mx==-1){
		cout << "0 1 " << endl;
		return 0;
	}
	cout << mx << " " << ct << endl;
	return 0;
}