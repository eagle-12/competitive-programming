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
	_cin;
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int len,x,prev;
	int i=0,j=2;
	for(x=1;x<n;x++){
		if(arr[x]-arr[x-1]!=0){
			prev=arr[x]-arr[x-1];
			j=x+1;
			break;
		}
	}
	len=j;
	//cout << j << endl;
	while(i<=j && i<n && j<n){
		if(arr[j]-arr[j-1]==0){
			j++;
			if(j==n){
				len=max(len,j-i);
				break;
			}
		}
		else if(arr[j]-arr[j-1]==1){
			if(prev==-1){
				j++;
				prev=1;
				if(j==n){
					len=max(len,j-i);
					break;
				}
				continue;
			}
			else{
				len=max(len,j-i);
				i=j-1;
				prev=arr[j]-arr[j-1];
				j++;
			}
		}
		else if(arr[j]-arr[j-1]==-1){
			if(prev==1){
				j++;
				if(j==n){
					len=max(len,j-i);
					break;
				}
				prev=-1;
				continue;
			}
			else{
				len=max(len,j-i);
				i=j-1;
				prev=arr[j]-arr[j-1];
				j++;
			}
		}
	}
	cout << len << endl;
	return 0;
}