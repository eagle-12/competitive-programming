#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string s,s1;
	int i=0,l,j=0,ct=0;
	cin >> s;
	s1="hello";
	l=s.length();
	while(i<l)
	{	
		if(s[i]==s1[j])
		{
			j++;
			ct++;
		}
		i++;
		if(j==5)
		{
			break;
		}
	}
	if(ct==5)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}
