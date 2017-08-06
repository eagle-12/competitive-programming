#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;


#define ll long long int

int main()
{
	int n,x;
	cin >> n;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	int sum=0,ans=0;
	for(int i=0;i<n;i++)
	{
		if(v[i]>=sum)
		{
			sum+=v[i];
			ans++;
		}
	}
	cout << ans << endl;
}
