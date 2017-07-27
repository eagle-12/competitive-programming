#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back


using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int arr[3]={0};
	for(int i=0;i<n;i++)
	{
		if(s[i]=='B')
		{
			arr[0]++;
		}
		else if(s[i]=='G')
		{
			arr[1]++;
		}
		else
		{
			arr[2]++;
		}
	}
	if(arr[0]==0 && arr[1]==0)
	{
		cout << "R";
	}
	else if(arr[0]==0 && arr[2]==0)
	{
		cout << "G";
	}
	else if(arr[2]==0 && arr[1]==0)
	{
		cout << "B";
	}
	else if(arr[0]>0 && arr[1]>0 && arr[2]>0)
	{
		cout << "BGR";
	}
	else
	{
		if(arr[0]==1 && arr[1]==1)
		{
			cout << "R";
		}
		else if(arr[0]==1 && arr[2]==1)
		{
			cout << "G";
		}
		else if(arr[2]==1 && arr[1]==1)
		{
			cout << "B";
		}
		else if(arr[0]==0)
		{
			if(arr[1]>1 && arr[2]>1)
			{
				cout << "BGR";
			}
			else if(arr[1]>1)
			{
				cout << "BR";
			}
			else if(arr[2]>1)
			{
				cout << "BG";
			}
		}
		else if(arr[1]==0)
		{
			if(arr[0]>1 && arr[2]>1)
			{
				cout << "BGR";
			}
			else if(arr[0]>1)
			{
				cout << "GR";
			}
			else if(arr[2]>1)
			{
				cout << "BG";
			}		
		}
		else if(arr[2]==0)
		{
			if(arr[0]>1 && arr[1]>1)
			{
				cout << "BGR";
			}
			else if(arr[0]>1)
			{
				cout << "GR";
			}
			else if(arr[1]>1)
			{
				cout << "BR";
			}		
		}
	}
}
