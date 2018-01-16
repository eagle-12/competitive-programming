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

int main(){
	_cin;
	int h,w;
	cin >> h >> w;
	char arr[h][w];
	int hor[h][w],ver[h][w];
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin >> arr[i][j];
			hor[i][j]=0;
			ver[i][j]=0;
		}
	}
	for(int i=0;i<h;i++){
		for(int j=1;j<w;j++){
			if(arr[i][j]=='.' && arr[i][j-1]=='.'){
				hor[i][j]=hor[i][j-1]+1;
			}
			else{
				hor[i][j]=hor[i][j-1];
			}
		}
	}
	for(int i=1;i<h;i++){
		for(int j=0;j<w;j++){
			if(arr[i][j]=='.' && arr[i-1][j]=='.'){
				ver[i][j]=1+ver[i-1][j];
			}
			else{
				ver[i][j]=ver[i-1][j];
			}
		}
	}
	for(int i=1;i<h;i++){
		for(int j=0;j<w;j++){
			hor[i][j]+=hor[i-1][j];
		}
	}
	for(int i=0;i<h;i++){
		for(int j=1;j<w;j++){
			ver[i][j]+=ver[i][j-1];
		}
	}
	/*for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cout << ver[i][j] << " ";
		}
		cout << endl;
	}
	cout << ver[1][2] << endl;*/
	int q,ans,r1,r2,c1,c2;
	cin >> q;
	for(int i=0;i<q;i++){
		cin >> r1 >> c1 >> r2 >> c2;
		r1--;
		r2--;
		c1--;
		c2--;
		if(r1>=1 && c1>=1){
			ans=hor[r2][c2]-hor[r1-1][c2]-hor[r2][c1]+hor[r1-1][c1];
			ans+=ver[r2][c2]-ver[r1][c2]-ver[r2][c1-1]+ver[r1][c1-1];
		}
		else if(c1>=1){
			ans=hor[r2][c2]-hor[r2][c1];
			//cout << ans << endl;
			ans+=ver[r2][c2]-ver[r2][c1-1];
		}
		else if(r1>=1){
			ans=hor[r2][c2]-hor[r1-1][c2];
			ans+=ver[r2][c2]-ver[r1][c2];
		}
		else{
			ans=hor[r2][c2];
			ans+=ver[r2][c2];
		}
		cout << ans << endl;
	}
	return 0;
}