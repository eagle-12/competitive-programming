#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


string s;

int main()
{
	int n;
	cin >> n;
	//string s;
	cin >> s;
	string ans;
	for(int i=0;i<n;i++)
	{
		ans+='1';
	}
	//cout << ans << endl;
	int mn,mx;
	int mid;
	int l=n;
	if(l%2==0)
	{
		mid = l/2;
	}
	else
	{
		mid = (l/2) + 1;
	}
	ans[mid-1] = s[0];
	mn = mid-1;
	mx = mid-1;
	l--;
	for(int i=1;i<n;i++)
	{
		if(l%2==0)
		{
			mid = l/2;
		}
		else
		{
			mid = (l/2) + 1;
		}
		int ct = 0;
		for(int j=0;j<n;j++)
		{
			if(ans[j]=='1')
			{
				ct++;
			}
			if(ct==mid)
			{
				ans[j] = s[i];
				break;
			}
		}
		l--;
	}
	cout << ans;
}


