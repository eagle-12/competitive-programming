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
	_cin;
	int n,fl;
	cin >> n;
	if(n%2==0)
	{
		for(int i=0;i<n/2;i++)
		{
			if(i%2==0)
			{
				cout << "aa";
			}
			else
			{
				cout << "bb";
			}
		}
	}
	else
	{
		for(int i=0;i<n/2;i++)
		{
			if(i%2==0)
			{
				cout << "aa";
				fl=0;
			}
			else
			{
				cout << "bb";
				fl=1;
			}
		}
		if(fl==0)
		{
			cout << "b";
			return 0;
		}
		cout << "a";
	}
}
