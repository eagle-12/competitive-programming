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
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ct=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			ct++;
		}
		else
		{
			ct++;
			break;
		}
	}
	cout << ct << endl;
}
