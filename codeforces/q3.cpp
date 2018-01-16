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

int n,r;
int drop[1000];
double cov[1000];
double y[1000];
int idx[1000];
double ans;

int main(){
	_cin;
	cin >> n >> r;
	for(int i=0;i<n;i++){
		cin >> drop[i];
	}
	//cout << (double)r << endl;

	cout<<fixed<<setprecision(10);
	for(int i=0;i<n;i++){
		if(i==0){
			y[0]=r;
			cout << r << " ";
			continue;
		}
		ans=r;
		for(int j=i-1;j>=0;j--){
			if(abs(drop[i]-drop[j])<=2*r){
				double a=(abs(drop[i]-drop[j])*abs(drop[i]-drop[j]));
				ans=max(ans,y[j]+sqrt(4*r*r-a));
			}
		}
		y[i]=ans;
		cout << fixed << setprecision(10) << y[i] << " ";
	}
	return 0;
}