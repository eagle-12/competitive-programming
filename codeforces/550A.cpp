#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back


using namespace std;

int main()
{
	string s;
	cin >> s;
	int l=s.size();
	int mn=0,mx=0;
	for(int i=0;i<l;i++)
	{
		if(mn==0)
		{
			if(s[i]=='A' && (i+1)<l && s[i+1]=='B' && mn==0)
			{
				mn=1;
				//i++;
				for(int j=i+2;j<l;j++)
				{
					if(s[j]=='B' && (j+1)<l &&s[j+1]=='A' )
					{
						mx=1;
						break;
					}
				}
				break;
			}
			
		}
		else
		{
			break;
		}
	}
	if(mn==1 && mx==1)
	{
		cout << "YES" << endl;
		return 0;
	}
	mn=0,mx=0;
	for(int i=0;i<l;i++)
	{
		if(mx==0)
		{
			if(s[i]=='B' && (i+1)<l && s[i+1]=='A' && mx==0)
			{
				mx=1;
				//i++;
				for(int j=i+2;j<l;j++)
				{
					if(s[j]=='A' && (j+1)<l &&s[j+1]=='B' )
					{
						mn=1;
						break;
					}
				}
				break;
			}
			
		}
		else
		{
			break;
		}
	}
	if(mn==1 && mx==1)
	{
		cout << "YES" << endl;
		return 0;
	}		
	cout << "NO" << endl;
	return 0;
}
