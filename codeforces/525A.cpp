#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back


using namespace std;

int main()
{
	int n,ct=0;
	cin >> n;
	string s;
	cin >> s;
	map<char,int> key;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		if(i%2==0)
		{
			if(key.find(s[i]-97+65)==key.end())
			{
				key[s[i]-97+65]=1;
			}
			else
			{
				key[s[i]-97+65]++;
			}
		}
		else
		{
			if(key.find(s[i])==key.end())
			{
				ct++;
			}
			else if(key[s[i]]>0)
			{
				key[s[i]]--;
			}
			else
			{
				ct++;
			}
		}
	}
	cout << ct;
}
