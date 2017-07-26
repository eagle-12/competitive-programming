#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	cin >> n;
	int ct = n/7;
	for(int i=0;i<ct;i++)
	{
		cout << "ROYGBIV";
	}
	if(n%7==1)
	{
		cout << "G";
	}
	else if(n%7==2)
	{
		cout << "GB";
	}
	else if(n%7==3)
	{
		cout << "GBI";
	}
	else if(n%7==4)
	{
		cout << "GBIV";
	}
	else if(n%7==5)
	{
		cout << "YGBIV";
	}
	else if(n%7==6)
	{
		cout << "OYGBIV";
	}
	
}
