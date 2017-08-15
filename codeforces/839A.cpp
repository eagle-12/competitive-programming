#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back


using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	int ct=0;
	int balance=0;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(ct<k)
		{
			balance+=arr[i];
			if(balance>=8)
			{
				ct+=8;
				balance-=8;
			}
			else
			{
				ct+=balance;
				balance=0;
			}
			ans++;
		}
		else
		{
			break;
		}
	}
	if(ct<k)
	{
		cout << "-1" << endl;
		return 0;
	}
	cout << ans << endl;
	return 0;
}
