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

int a[1000][1000];
int a_2[1000][1000];
int a_5[1000][1000];
int n;
int dp[1000][1000];

pair<int,pair<int,int> > compute(int x){
	pair<int,pair<int,int> > p;
	p.fi=0;
	p.se.fi=0;
	p.se.se=0;
	while(x%10==0){
		x=x/10;
		p.fi++;
	}
	while(x%2==0){
		p.se.fi++;
		x=x/2;
	}
	while(x%5==0){
		p.se.se++;
		x/=5;
	}
	return p;
}

int calc(int r,int c){
	if(r==0 && c==0){
		dp[r][c]=a[0][0];
		return dp[r][c];
	}
	if(dp[r][c]!=-1){
		return dp[r][c];
	}
	if(r==0){
		dp[r][c]=calc(r,c-1)+arr[r][c]+min(a_2[r][c],a_5[r][c-1])+min(a_5[r][c],a_2[r][c-1]);
		a_2[r][c]+=a_2[r][c-1]-(min(a_2[r][c],a_5[r][c-1])+min(a_5[r][c],a_2[r][c-1]));
		a_5[r][c]+=a_5[r][c-1]-(min(a_2[r][c],a_5[r][c-1])+min(a_5[r][c],a_2[r][c-1]));
		return dp[r][c];
	}
	else if(c==0){
		dp[r][c]=calc(r-1,c)+arr[r][c]+min(a_2[r][c],a_5[r-1][c])+min(a_5[r][c],a_2[r-1][c]);
		a_2[r][c]+=a_2[r-1][c]-(min(a_2[r][c],a_5[r-1][c])+min(a_5[r][c],a_2[r-1][c]));
		a_5[r][c]+=a_5[r-1][c]-(min(a_2[r][c],a_5[r-1][c])+min(a_5[r][c],a_2[r-1][c]));
		return dp[r][c];
	}

}

int main(){
	int n;
	cin >> n;
	pair<int,pair<int,int> > p;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> x;
			p=compute(x);
			a[i][j]=p.fi;
			a_2[i][j]=p.se.fi;
			a_5[i][j]=p.se.se;
			dp[i][j]=-1;
		}
	}
	cout << calc(n-1,n-1) << endl;
	return 0;
}