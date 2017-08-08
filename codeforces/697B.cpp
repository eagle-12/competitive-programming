#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cmath>
using namespace std;


#define ll long long int

int power(int i)
{
	int ans=1;
	for(int j=1;j<=i;j++)
	{
		ans*=10;
	}
	return ans;
}

int main()
{
	string s;
	cin >> s;
	int pow1=0;
	int l=s.size()-1;
	int i=0;
	while(s[l]!='e')
	{
		pow1+=(int)(s[l]-'0')*pow(10,i);
		//cout << (10^0) << endl;
		i++;
		l--;
	}
	//cout << pow1 << endl;
	string s1;
	l=0;
	while(s[l]!='e')
	{
		s1+=s[l++];
	}
	l=0;
	while(s[l]!='.')
	{
		l++;
	}
	int idx=s1.size()-l-1;
	//cout << s1 << endl;
	//cout << idx << endl;
	if(pow1>idx)
	{
		for(int i=0;i<s1.size();i++)
		{
			if(s1[i]!='.')
			{
				cout << s1[i];
			}
		}
		//for(int j=i;j<)
		pow1-=idx;
		//cout << pow1 << endl;
		for(int i=0;i<pow1;i++)
		{
			cout << "0";
		}
		cout << endl;
	}
	else if(pow1==idx)
	{
		for(int i=0;i<s1.size();i++)
		{
			if(s1[i]!='.')
			{
				cout << s1[i];
			}
		}
	}
	else
	{
		//cout << s1 << endl;
		int i=0;
		for(i=0;i<s1.size();i++)
		{
			if(s1[i]!='.')
			{
				cout << s1[i];
			}
			else
			{
				break;
			}
		}
		i++;
		//cout << i << endl;
		for(int j=0;j<pow1;j++)
		{
			cout << s1[i];
			i++; 
		}
		cout << ".";
		while(i<s1.size())
		{
			cout << s1[i++];
		}
		cout << endl;
	}
}
