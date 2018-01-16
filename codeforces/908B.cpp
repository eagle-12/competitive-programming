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

char arr[100][100];
vi v(4);
string s;
int ans=0,x1,y,ex,ey;
map<int,char> m;
int n,c;

void calc(int i,int j,int k){
	int sx=x1,sy;
	sy=y;
	int a=10-i-j-k;
	for(int x=0;x<s.size();x++){
		//cout << sx << " " << sy << endl;;
		if(s[x]=='0'){
			if(m[i]=='R'){
				sy++;
			}
			else if(m[i]=='D'){
				sx++;
			}
			else if(m[i]=='L'){
				sy--;
			}
			else if(m[i]=='U'){
				sx--;
			}
		}
		else if(s[x]=='1'){
			if(m[j]=='R'){
				sy++;
			}
			else if(m[j]=='D'){
				sx++;
			}
			else if(m[j]=='L'){
				sy--;
			}
			else if(m[j]=='U'){
				sx--;
			}	
		}
		else if(s[x]=='2'){
			if(m[k]=='R'){
				sy++;
			}
			else if(m[k]=='D'){
				sx++;
			}
			else if(m[k]=='L'){
				sy--;
			}
			else if(m[k]=='U'){
				sx--;
			}
		}
		else if(s[x]=='3'){
			if(m[a]=='R'){
				sy++;
			}
			else if(m[a]=='D'){
				sx++;
			}
			else if(m[a]=='L'){
				sy--;
			}
			else if(m[a]=='U'){
				sx--;
			}
		}
		if(sx>=n || sx<0 || sy>=c || sy<0){
			return;
		}
		if(arr[sx][sy]=='#'){
			return;
		}
		if(arr[sx][sy]=='E'){
			//cout << i << j << k << endl;
			ans++;
			return;
		}
	}
	if(arr[sx][sy]=='E'){
		ans++;
		return;
	}
}

int main(){
	_cin;
	cin >> n >> c;
	m[1]='R';
	m[2]='D';
	m[3]='L';
	m[4]='U';
	for(int i=0;i<n;i++){
		for(int j=0;j<c;j++){
			cin >> arr[i][j];
			if(arr[i][j]=='S'){
				x1=i;
				y=j;
			}
			if(arr[i][j]=='E'){
				ex=i;
				ey=j;
			}
		}
	}
	//cout << x1 << y << endl;
	cin >> s;
	//calc(1,4,3);
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			for(int k=1;k<=4;k++){
				if(i!=j && i!=k && j!=k){
					calc(i,j,k);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}