#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back


using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=(n-k-1);i++)
	{
		cout << i << " ";
	}
	for(int i=n;i>=(n-k);i--)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
