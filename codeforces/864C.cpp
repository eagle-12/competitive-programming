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
	int a,b,f,k,p,ans=0;
	cin >> a >> b >> f >> k;
	p=b;
	for(int i=0;i<k-1;i++)
	{
		if(i%2==0)
		{
			if(p>=(2*a-f))
			{
				p-=a;
			}
			else
			{
				p=b-a+f;
				ans++;
				if(b<2*(a-f))
				{
					cout << -1 << endl;
					return 0;
				}
			} 
		}
		else
		{
			if(p>=a+f)
			{
				p-=a;
			}
			else
			{
				p=b-f;
				ans++;
				if(b<2*f)
				{
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}
	if(p>=a)
	{
		cout << ans << endl;
	} 
	else
	{
		if(k%2==0)
		{
			if(p<(a-f))
			{
				cout << -1 << endl;
				return 0;
			}
			else
			{
				if(p<a)
				{
					ans++;
					if(b>=f)
					{
						cout << ans << endl;
					}
					else
					{
						cout << -1 << endl;
					}
				}
				else
				{
					cout << ans << endl;
				}
			}
		}
		else
		{
			if(p<f)
			{
				cout << -1 << endl;
			}			
			else
			{
				if(p<a)
				{
					ans++;
					if(b<(a-f))
					{
						cout << -1 << endl;
					}
					else
					{
						cout << ans << endl;
					}
				}
				else
				{
					cout << ans << endl;
				}
			}
		}
	}
	return 0;
}
