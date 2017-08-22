#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

int main()
{
	string s;
	int k,ct=0,nct=0;
	cin >> s >> k;
	int l=s.size();
	for(int i=l-1;i>=0;i--)
	{
		if(s[i]=='0')
		{
			ct++;
		}
		else
		{
			nct++;
		}
		if(ct==k)
		{
			cout << nct << endl;
			return 0;
		}
	}
	cout << nct + ct-1 << endl;
	return 0;
}
