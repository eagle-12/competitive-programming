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

vector<string> v(100000);
vector<int> c(100000);
ll n;
ll dp[100000][2];
ll MAX=1000000000000001;

int compare(string s,string s1){
	for(int i=0;i<min(s.size(),s1.size());i++){
		if(s[i]<s1[i]){
			return 1;
		}
		else if(s1[i]<s[i]){
			return 0;
		}
	}
	if(s.size()<s1.size()){
		return 1;
	}
	else if(s1.size()<s.size()){
		return 0;
	}
	return 1;
}

void calc(ll x){
	if(x==n-1){
		dp[n-1][0]=0;
		dp[n-1][1]=c[n-1];
		return;
	}
	string s=v[x+1];
	string s1=v[x];
	reverse(s.begin(),s.end());
	reverse(s1.begin(),s1.end());
	int a=compare(v[x],v[x+1]);
	int b=compare(v[x],s);
	int y=compare(s1,v[x+1]);
	int z=compare(s1,s);
	//cout << a << b << y << z << endl;
	calc(x+1);
	if(a==1 && b==1){
		dp[x][0]=min(dp[x+1][0],dp[x+1][1]);
	}
	else if(a==1){
		dp[x][0]=dp[x+1][0];
	}
	else if(b==1){
		dp[x][0]=dp[x+1][1];
	}
	if(y==1 && z==1){
		dp[x][1]=c[x]+min(dp[x+1][0],dp[x+1][1]);
	}
	else if(y==1){
		dp[x][1]=c[x]+dp[x+1][0];
	}
	else if(z==1){
		dp[x][1]=c[x]+dp[x+1][1];
	}	
}

int main(){
	_cin;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> c[i];
		dp[i][0]=MAX;
		dp[i][1]=MAX;
	}
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	calc(0);
	ll ans=min(dp[0][0],dp[0][1]);
	if(ans==MAX){
		cout << -1 << endl;
	}
	else{
		cout << ans << endl;
	}
	return 0;
}