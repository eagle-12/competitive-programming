#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back
#define fi first
#define se second
#define mp make_pair

#define lb(x, k)   lower_bound(all(x), k)-x.begin()
//first element not less than (i.e. greater or equal to) k
#define ub(x, k)   upper_bound(all(x), k)-x.begin()
//first element greater than k


ll mod = 1000000007;

using namespace std;

int main()
{
	string s;
	cin >> s;
	int ans=0;
	//int s1=(s[0]-'0')+(s[1]-'0')+(s[2]-'0');
	//int s2=(s[3]-'0')+(s[4]-'0')+(s[5]-'0');
	vector<int> v;
	vector<int> v1;
	v.pb((s[0]-'0'));
	v.pb((s[1]-'0'));
	v.pb((s[2]-'0'));
	v1.pb((s[3]-'0'));
	v1.pb((s[4]-'0'));
	v1.pb((s[5]-'0'));
	int s1=v[0]+v[1]+v[2];
	int s2=v1[0]+v1[1]+v1[2];
	sort(v.begin(),v.end());
	sort(v1.begin(),v1.end());
	if(s1==s2)
	{
		cout << "0" << endl;
		return 0;
	}
	if(s1>s2)
	{
		if((s1-s2)<=9)
		{
			cout << 1 << endl;
		}
	}
	else
	{
		if((s2-s1)<=9)
		{
			cout << 1 << endl;
		}
	}
	
	
}
