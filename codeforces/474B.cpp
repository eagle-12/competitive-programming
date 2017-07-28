#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back


using namespace std;

int search(int arr[],int low,int high,int key)
{
	while(low<=high)
	{
		int mid = (low+high)/2;
		if(arr[mid]==key)
		{
			return mid;
		}
		else if(arr[mid]>key && arr[mid-1]<key)
		{
			return mid;
		}
		else if(arr[mid]<key && arr[mid+1]>key)
		{
			return mid+1;
		}
		else if(arr[mid]>key)
		{
			high = mid-1;
		}
		else if(arr[mid]<key)
		{
			low = mid+1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	for(int i=1;i<n;i++)
	{
		arr[i]=arr[i]+arr[i-1];
	}
	int m,ans;
	cin >> m;
	int x;
	for(int i=0;i<m;i++)
	{
		cin >> x;
		ans=search(arr,0,n-1,x);
		cout << ans+1 << endl;
	}
}
