#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;


#define ll long long int

int main()
{
	int t,s,x;
	cin >> t >> s >> x;
	if(x<t)
	{
		cout << "NO" << endl;
		return 0; 
	}
	x-=t;
	if(x%s==0 ||((x-1)%s==0 && x/s>0))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}
