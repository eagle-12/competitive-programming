#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	int n,k1,k2;
	cin >> n;
	cin >> k1;
	int arr[k1];
	queue<int> q1;
	queue<int> q2;
	for(int i=0;i<k1;i++)
	{
		cin >> arr[i];
		q1.push(arr[i]);
	}
	cin >> k2;
	int arr2[k2];
	for(int i=0;i<k2;i++)
	{
		cin >> arr2[i];
		q2.push(arr2[i]);
	}
	int ct=0,ans=0;
	while(ct<110 && q1.size()!=0 && q2.size()!=0)
	{
		if(q1.front()<q2.front())
		{
			q2.push(q1.front());
			q1.pop();
			q2.push(q2.front());
			q2.pop();
			ans=2;
		}
		else
		{
			q1.push(q2.front());
			q2.pop();
			q1.push(q1.front());
			q1.pop();
			ans=1;
		}
		ct++;
	}
	if(ct==110)
	{
		cout << "-1";
	}
	else
	{
		cout << ct << " " << ans;
	}
}
