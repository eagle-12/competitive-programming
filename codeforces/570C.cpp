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
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	int l=s.size();
	int i=0,j;
	int ans=0;
	while(i<l)
	{
		if(s[i]=='.')
		{
			int ct=0;
			for(j=i+1;j<l;j++)
			{
				if(s[j]!='.')
				{
					//ans+=(j-i);
					break;
				}
				else
				{
					ct++;
				}
				
			}
			ans+=ct;
			i=j+1;
		}
		else
		{
			i++;
		}
	}
	//cout << ans << endl;
	char c;
	int x,b,a;
	for(int i=0;i<m;i++)
	{
		cin >> x >> c;
		x--;
		if(c=='.' && s[x]=='.')
		{
			cout << ans << endl;
		}
		else if(c=='.')
		{
			s[x]=c;
			b=1;
			a=1;
			if(x==0)
			{
				b=0;
				if(s[x+1]!='.')
				{
					a=0;
				}
			}
			else if(x==l-1)
			{
				a=0;
				if(s[x-1]!='.')
				{
					b=0;
				}
			}
			else if(s[x-1]!='.' && s[x+1]!='.')
			{
				b=0;
				a=0;
			}
			else if(s[x+1]!='.' && s[x-1]=='.')
			{
				a=0;
			}
			else if(s[x+1]=='.' && s[x-1]!='.')
			{
				b=0;
			}
			if(a*b==1)
			{
				cout << ans+2 << endl;
				ans+=2;
			}
			else if((a==1 && b==0) || (a==0 && b==1))
			{
				cout << ans+1 << endl;
				ans++;
			}
			else
			{
				cout << ans << endl;
			}
		}
		else
		{
			b=1;
			a=1;
			if(s[x]!='.')
			{
				cout << ans << endl;
			}
			else
			{
				if(x==0)
				{
					b=0;
					if(s[x+1]!='.')
					{
						a=0;
					}
				}
				else if(x==l-1)
				{
					a=0;
					if(s[x-1]!='.')
					{
						b=0;
					}
				}
				else if(s[x+1]!='.' && s[x-1]!='.')
				{
					a=0;
					b=0;
				}
				else if(s[x+1]!='.' && s[x-1]=='.')
				{
					a=0;
				}
				else if(s[x-1]!='.' && s[x+1]=='.')
				{
					b=0;
				}
				if(a==0 && b==0)
				{
					cout << ans << endl;
				}
				else if(a==1 && b==1)
				{
					cout << ans-2 << endl;
					ans-=2;
				}
				else
				{
					cout << ans-1 << endl;
					//cout << a << b << i << endl;
					ans-=1;
				}
			}
			s[x]=c;
		}
	}
}




