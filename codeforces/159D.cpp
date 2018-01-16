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

int palindrome[2000][2000];
ll dp[2000];
ll ans[2000]={0};
string s;

int pal(int x,int y){
	if(x>y){
		return 0;
	}
	while(x<=y){
		if(s[x]==s[y]){
			x++;
			y--;
		}
		else{
			return 0;
		}
	}
	return 1;
}

int main(){
	cin >> s;
	for(int i=0;i<s.size();i++){
		for(int j=0;j<s.size();j++){
			palindrome[i][j]=pal(i,j);
		}
		dp[i]=0;
	}
	/*for(int i=0;i<s.size();i++){
		for(int j=0;j<s.size();j++){
			cout << palindrome[i][j] << " ";
		}
		cout << endl;
	}*/
	for(int i=0;i<s.size();i++){
		if(i!=0){
			dp[i]=dp[i-1];
		}
		for(int x=0;x<=i;x++){
			dp[i]+=palindrome[x][i];
		}
	}
	//cout << dp[0] << " " << dp[1]  << " " << dp[2]<< endl;
	for(int i=1;i<s.size();i++){
		ans[i]=ans[i-1];
		for(int x=1;x<=i;x++){
			ans[i]+=palindrome[x][i]*dp[x-1];
		}
	}
	cout << ans[s.size()-1];
	return 0;
}