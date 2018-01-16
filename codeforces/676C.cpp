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
	string s;
	cin >> s;
	int a=0,b=0,l=0,st=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='a')
		{
			a++;
		}
		else
		{
			b++;
		}
		if(min(a,b)<=k)
		{
			l=max(l,a+b);
		}
		else
		{
			if(s[st]=='a')
			{
				a--;
				st++;
			}
			else
			{
				b--;
				st++;
			}
		}
	}
	cout << l << endl;
}
