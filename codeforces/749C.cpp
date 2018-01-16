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
	int n;
	cin >> n;
	string s;
	cin >> s;
	queue<int> D;
	queue<int> R;
	queue<int> D1;
	queue<int> R1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='D'){
			D.push(i);
		}
		else{
			R.push(i);
		}
	}
	//cout << D.size() << endl;
	//cout << R.size() << endl;
	int x;
	while(D.size()!=0 && R.size()!=0){
		if(D.front()<R.front()){
			R.pop();
			x=D.front();
			D.pop();
			D1.push(x);
		}
		else if(R.front()<D.front()){
			D.pop();
			x=R.front();
			R.pop();
			R1.push(x);
		}
		if(D.size()==0||R.size()==0){
			while(D.size()!=0){
				if(R1.size()!=0){
					R1.pop();
				}
				x=D.front();
				D.pop();
				D1.push(x);
			}
			while(R.size()!=0){
				if(D1.size()!=0){
					D1.pop();
				}
				x=R.front();
				R.pop();
				R1.push(x);
			}
			while(D1.size()!=0){
				x=D1.front();
				D1.pop();
				D.push(x);
			}
			while(R1.size()!=0){
				x=R1.front();
				R1.pop();
				R.push(x);
			}
		}
	}
	if(D.size()==0){
		cout << "R" << endl;
		return 0;
	}
	cout << "D" << endl;
	return 0;
}