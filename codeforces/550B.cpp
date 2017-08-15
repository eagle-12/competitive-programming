#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back


using namespace std;

string binary(int num,int n)
{
	int ct=0;
	string s;
	while(ct<=n)
	{
		s+='0'+num%2;
		num/=2;
		ct++;
	}
	return s;
}

int main()
{
	int n,l,r,x;
	cin >> n >> l >> r >> x;
	ll arr[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	int mx=pow(2,n);
	ll ct=0;
	//cout << mx << endl;
	for(int i=0;i<mx;i++)
	{
		string s = binary(i,n);
		vector<int> v;
		ll sum=0;
		ll mn=1000001;
		ll mx=-1;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='1')
			{
				v.push_back(arr[i]);
				sum+=arr[i];
				mn=min(mn,arr[i]);
				mx=max(mx,arr[i]);
			}
		}
		if(sum>=l && sum<=r && (mx-mn)>=x)
		{
			ct++;
		}
	}
	cout << ct << endl;
}
