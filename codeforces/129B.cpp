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

int arr[101][101];
int ct[101]={0};

int main(){
	int n,m,x,y,ans=0;
	cin >> n >> m;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			arr[i][j]=0;
		}
	}
	for(int i=0;i<m;i++){
		cin >> x >> y;
		arr[x][y]=1;
		arr[y][x]=1;
		ct[x]++;
		ct[y]++;
	}
	//cout << ct[1] << " " << ct[2] << " " << ct[3] << " " << ct[4];
	int fl=0;
	vector<int> v;
	do{
		fl=0;
		for(int i=1;i<=n;i++){
			if(ct[i]==1){
				//cout << ct[i] << endl;
				ct[i]--;
				for(int j=1;j<=n;j++){
					if(arr[i][j]==1){
						arr[j][i]=0;
						arr[i][j]=0;
						v.pb(j);	
						break;
					}
				}
				fl=1;
			}
		}
		if(fl==1){
			ans++;
			for(int j=0;j<v.size();j++){
				ct[v[j]]--;
			}
			v.clear();
		}
	}while(fl==1);
	cout << ans << endl;
	return 0;
}