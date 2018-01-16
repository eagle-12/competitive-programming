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

vector<string> v(505);
int n,m,r1,c1,r2,c2;

int isValid(int r, int c)
{
	if(r < 0 || c < 0 || r >= n || c >= m){
		return 0;
	}
	else{
		return 1;
	}
}

int dfs(int r, int c)
{
	//cout << r << " " << c << endl;
	if(v[r][c] == 'X'){
		if(r == r2 && c == c2){
			return 1;
		}
		else{ 
			return 0;
		}
	}
	v[r][c] = 'X';
	if(isValid(r+1, c) && dfs(r+1,c)){
		return 1;
	}
	if(isValid(r-1, c) &&  dfs(r-1,c)){
		return 1;
	}
	if(isValid(r, c-1) && dfs(r,c-1)){
		return 1;
	}
	if(isValid(r, c+1) && dfs(r,c+1)){
		return 1;
	}
	return 0;
}

int main()
{
	cin >> n >> m;
	for(int i=0; i<n; i++)
		cin >> v[i];
	cin >> r1 >> c1;
	cin >> r2 >> c2;
	r1--;
	c1--;
	r2--;
	c2--;
	v[r1][c1]='.';
	if(dfs(r1,c1)){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	return 0;
}