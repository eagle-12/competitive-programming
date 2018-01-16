#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back
#define fi first
#define se second
#define mp make_pair
#define _cin ios_base::sync_with_stdio(0);  cin.tie(0);

#define lb(x, k)   lower_bound(all(x), k)-x.begin()
//first element not less than (i.e. greater or equal to) k
#define ub(x, k)   upper_bound(all(x), k)-x.begin()
//first element greater than k


ll mod = 1000000007;

using namespace std;

int main()
{
	_cin;
	int n;
	cin >> n;
	int arr[n],brr[n-1],crr[n-2];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	for(int i=0;i<n-1;i++)
	{
		cin >> brr[i];
	}
	for(int i=0;i<n-2;i++)
	{
		cin >> crr[i];
	}
	sort(arr,arr+n);
	sort(brr,brr+n-1);
	sort(crr,crr+n-2);
	int fl=0;
	for(int i=0;i<n-1;i++)
	{
		if(arr[i]!=brr[i])
		{
			cout << arr[i] << endl;
			fl=1;
			break;
		}
	}
	if(!fl)
	{
		cout << arr[n-1] << endl;
	}
	fl=0;
	for(int i=0;i<n-2;i++)
	{
		if(brr[i]!=crr[i])
		{
			cout << brr[i] << endl;
			fl=1;
			break;
		}
	}
	if(!fl)
	{
		cout << brr[n-2] << endl;
	}
		
}
