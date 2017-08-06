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
	int n,m,x;
	vector<int> b,g;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> x;
		b.push_back(x);
	}
	cin >> m;
	for(int i=0;i<m;i++)
	{
		cin >> x;
		g.push_back(x);
	}
	sort(b.begin(),b.end());
	sort(g.begin(),g.end());
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(abs(b[i]-g[j])<=1)
			{
				ans++;
				g[j]=200;
				break;
			}
		}
	}
	cout << ans << endl;
}
