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
	ll n;
	cin >> n;
	if(n>0)
	{
		cout << n << endl;
	}
	else
	{
		ll num = -1*n;
		ll ele;
		if(num/100==0)
		{
			ll ans=min(num%10,(num/10)%10);
			cout << ans*-1 << endl;
		}
		else
		{
			if((num%10)<(num/10)%10)
			{
				ele=num%10;
				num=num/100;
				num=num*10;
				num+=ele;
				cout << num*-1 << endl;
			}
			else
			{
				ele=(num/10)%10;
				num=num/100;
				num=num*10;
				num+=ele;
				cout << num*-1 << endl;
			}
		}
		
	}
}
