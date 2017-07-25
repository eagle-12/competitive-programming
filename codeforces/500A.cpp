#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void dfs(int x);
int n,t;
vector<vector<int> > v(30001);
int flag[30001]={0};
int main()
{	
	int x;
	cin >> n >> t;
	for(int i=1;i<n;i++)
	{
		cin >> x;
		v[i].push_back(x+i);
	}

	flag[1]=1;
	dfs(1);
	if(flag[t]==1)
	{
		cout << "YES";
	}		
	else
	{
		cout << "NO";
	}
}
void dfs(int x)
{
	flag[x]=1;
	for(int i=0;i<v[x].size();i++)
	{	
		int k=v[x][i];
		if(flag[k]==0)
		{
			dfs(k);
		}
	}
}
