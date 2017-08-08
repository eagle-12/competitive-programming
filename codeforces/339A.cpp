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
	int l=s.size();
	int arr[4]={0};
	for(int i=0;i<l;i++)
	{
		if(s[i]=='+')
		{
			arr[0]++;
		}
		else
		{
			arr[s[i]-'0']++;
		}
	}
	while(arr[1]!=0)
	{
		cout << 1;
		if(arr[0]!=0)
		{
			cout << "+";
			arr[0]--;
		}
		arr[1]--;
	}
	while(arr[2]!=0)
	{
		cout << 2;
		if(arr[0]!=0)
		{
			cout << "+";
			arr[0]--;
		}
		arr[2]--;
	}
	while(arr[3]!=0)
	{
		cout << 3;
		if(arr[0]!=0)
		{
			cout << "+";
			arr[0]--;
		}
		arr[3]--;
	}
}
