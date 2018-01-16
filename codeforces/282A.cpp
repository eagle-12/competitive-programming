#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back
#define fi first
#define se second
#define mp make_pair

#define lb(x, k)   lower_bound(all(x), k)-x.begin()
//first element not less than (i.e. greater or equal to) k
#define ub(x, k)   upper_bound(all(x), k)-x.begin()
//first element greater than k


ll mod = 1000000007;

using namespace std;

int main()
{
	int m,x=0;
	string s;
	cin >> m;
	for(int i=0;i<m;i++)
	{
		cin >> s;
		if(s[1]=='+')
		{
			x++;
		}
		else
		{
			x--;
		}
	}
	cout << x << endl;
	return 0;
}
