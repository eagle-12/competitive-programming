#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	string s;
	cin >> s;
	string s1;
	cin >> s1;
	string test;
	cin >> test;
	char arr[26];
	int ele;
	for(int i=0;i<26;i++)
	{
		arr[(int)s[i]-97] = s1[i];
	}
	string ans;
	for(int i=0;i<test.size();i++)
	{
		if(test[i]=='0' || test[i]=='1'|| test[i]=='2'|| test[i]=='3'|| test[i]=='4'|| test[i]=='5'|| test[i]=='6'|| test[i]=='7'|| test[i]=='8' || test[i]=='9')
		{
			ans+=test[i];
		}
		else
		{
			ele = (int)test[i];
			if(ele>=97 && ele<=122)
			{
				ans+=arr[ele-97];
			}
			else
			{
				ele+=32;
				ele = (int)arr[ele-97];
				ele = ele-32;
				ans+=(char)ele;
			}
		}
	}
	//cout << (char)97 << endl;
	cout << ans;
}
