#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int i,x,y,z,n,ct=0;
	cin >> n;
	for(i=0;i<n;i++)
	{
		cin >> x >> y >> z;
		if(x+y+z>1)
		{
			ct++;
		}
	}

	cout << ct;
}
