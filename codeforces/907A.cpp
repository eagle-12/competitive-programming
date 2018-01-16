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

int arr[3][2];

int main(){
	int v1,v2,v3,v4;
	cin >> v1 >> v2 >> v3 >> v4;
	arr[0][0]=v1;
	arr[0][1]=2*v1;
	arr[1][0]=v2;
	arr[1][1]=2*v2;
	arr[2][0]=v3;
	arr[2][1]=2*v3;
	if(2*v4<2*v3){
		arr[2][1]=2*v4;
	}
	else{
		arr[2][0]=v4;
	}
	if(arr[0][0]<=arr[0][1] && arr[1][0]<=arr[1][1] && arr[2][0]<=arr[2][1]){
		for(int i=arr[0][0];i<=arr[0][1];i++){
			for(int j=arr[1][0];j<=arr[1][1];j++){
				for(int k=arr[2][0];k<=arr[2][1];k++){
					if(i>j && j>k && 2*v4<i && 2*v4<j){
						cout << i << endl;
						cout << j << endl;
						cout << k << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
