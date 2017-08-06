#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;


#define ll long long int

int main()
{
	string s,s1;
	cin >> s;
	cin >> s1;
	int ct=0;
	string ans;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s1[i])
		{
			ct++;
		}
	}
	if(ct%2!=0)
	{
		cout << "impossible" << endl;
	}
	else
	{
		int it=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]!=s1[i])
			{
				if(it<ct/2)
				{
					ans+=s[i];
					it++;
				}
				else
				{
					ans+=s1[i];
					it++;
				}
			}
			else
			{
				ans+=s[i];
			}
		}		
		cout << ans << endl;
	}
}
