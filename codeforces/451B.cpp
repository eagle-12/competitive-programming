#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,front=0,back=0;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	for(int i=1;i<n;i++)
	{
		if(arr[i]<arr[i-1])
		{
			front = i-1;
			break;
		}
	}
	for(int i=n-2;i>=0;i--)
	{
		if(arr[i]>arr[i+1])
		{
			back = i+1;
			break;
		}
	}
	for(int i=front;i<back;i++)
	{
		if(arr[i]>arr[i+1])
		{
			continue;
		}
		else
		{
			cout << "no" ;
			return 0;
		}
	}
	if(back!=n-1 && arr[front]<arr[back+1] && front!=0 && arr[back]>arr[front-1])
	{
		cout << "yes" << endl;
		cout << front+1 << " " << back+1;
	}
	else if(back==n-1 && front!=0 && arr[back]>arr[front-1])
	{
		cout << "yes" << endl;
		cout << front+1 << " " << back+1;		
	}
	else if(front==0 && back!=n-1 && arr[front]<arr[back+1])
	{
		cout << "yes" << endl;
		cout << front+1 << " " << back+1;		
	}
	else if(front==0 && back==n-1)
	{
		cout << "yes" << endl;
		cout << front+1 << " " << back+1;
	}
	else if(front==0 && back==0)
	{
		cout << "yes" << endl;
		cout << 1 << " " << 1; 
	}
	else
	{
		cout << "no";
	}
	return 0;
}
