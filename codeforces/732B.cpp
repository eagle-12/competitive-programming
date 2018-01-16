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

int main()
{
	int n,k;
	cin >> n >> k;
	vector<int> v(n);
	//vector<int> ans(n);
	for(int i=0;i<n;i++)
	{
		cin >> v[i];
		//ans[i]=v[i];
	}
	int prev=k;
	int ct=0;
	for(int i=0;i<n;i++)
	{
		if((prev+v[i])<k)
		{
			ct+=(k-(prev+v[i]));
			v[i]+=(k-prev-v[i]);
		}
		prev=v[i];
	}
	cout << ct << endl;
	for(int i=0;i<n;i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}
