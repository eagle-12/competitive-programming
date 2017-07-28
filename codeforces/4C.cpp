#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back


using namespace std;

int main()
{
	map<string,int> reg;
	int n;
	cin >> n;
	string s,s1;
	for(int i=0;i<n;i++)
	{
		cin >> s;
		if(reg.find(s)==reg.end())
		{
			reg[s] = 1;
			cout << "OK" << endl;
		}
		else
		{
			reg[s]+=1;
			s1 = to_string(reg[s]-1);
			s=s+s1;
			cout << s << endl;
		}
	}
}
