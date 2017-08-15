#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cmath>
using namespace std;


#define ll long long int

int main()
{
	ll n,c;
	cin >> n >> c;
	ll arr[n];
	for(ll i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	ll ct=1;
	for(ll i=1;i<n;i++)
	{
		if(arr[i]-arr[i-1]<=c)
		{
			ct++;
		}
		else
		{
			ct=1;
		}
	}
	cout << ct << endl;
}
