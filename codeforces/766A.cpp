#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string a,b;
	cin >> a;
	cin >> b;
	if(a==b)
	{
		cout << "-1";
	}
	else
	{
		cout << max(a.size(),b.size());
	}
	return 0;
}
