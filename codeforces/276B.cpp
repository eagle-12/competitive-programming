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
	string s;
	cin >> s;
	int ct=0;
	int arr[26]={0};
	for(int i=0;i<s.size();i++){
		arr[s[i]-'a']++;
	}
	for(int i=0;i<26;i++){
		if(arr[i]%2==1){
			ct++;
		}
	}
	if(ct==0){
		cout << "First" << endl;
		return 0;
	}
	if(ct%2==0){
		cout << "Second" << endl;
	}
	else{
		cout << "First" << endl;
	}
	return 0;
}