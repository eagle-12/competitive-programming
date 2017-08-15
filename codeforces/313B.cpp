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
	string s;
	cin >> s;
	int m,x,r;
	cin >> m;
	int l=s.size();
	int arr[s.size()];
	for(int i=0;i<l;i++)
	{
		arr[i]=0;
	}
	for(int i=1;i<l;i++)
	{
		if(s[i]==s[i-1])
		{
			arr[i]=1;
		}
	}
	for(int i=1;i<l;i++)
	{
		arr[i]+=arr[i-1];
	}
	while(m--)
	{
		cin >> x >> r;
		cout << arr[r-1]-arr[x-1] << endl;
	}
}
