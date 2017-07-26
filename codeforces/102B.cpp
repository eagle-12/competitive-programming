#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	string str;
	cin >> str;
	//cout << str.size();
	int ct=0;
	while(str.size()!=1)
	{
		int sum=0;
		for(int i=0;i<str.size();i++)
		{
			sum+=str[i]-'0';
		}
		str = to_string(sum);
		ct++;
	}
	cout << ct;
}
