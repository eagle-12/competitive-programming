#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back


using namespace std;

int main()
{
	string s;
	cin >> s;
	int l=s.size();
	int k=0;
	int arr[l];
	for(int i=0;i<l;i++)
	{
		arr[i]=(int)(s[i]-'0');
	}
	int ele=0;
	for(int i=0;i<l;i++)
	{
		if(arr[i]%8==0)
		{
			cout << "YES"<< endl;
			cout << arr[i] << endl;
			return 0;
		}
	}
	for(int i=0;i<l-1;i++)
	{
		if(arr[i]!=0)
		{
			for(int j=i+1;j<l;j++)
			{
				ele=arr[i]*10+arr[j];
				if(ele%8==0)
				{
					cout << "YES"<< endl;
					cout << ele << endl;
					return 0;
				}
			}
		}
	}
	for(int i=0;i<l-2;i++)
	{
		if(arr[i]!=0)
		{
			for(int j=i+1;j<l-1;j++)
			{
				for(int k=j+1;k<l;k++)
				{
					ele=arr[i]*100+arr[j]*10+arr[k];
					if(ele%8==0)
					{
						cout << "YES" << endl;
						cout << ele << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}
