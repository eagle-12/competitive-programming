#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long int n,k;
	cin >> n >> k;
	long long int a = n/k;
	if(a%2==0)
	{
		cout << "NO" << endl;
	}
	else
	{
		cout << "YES" << endl;
	}
}
