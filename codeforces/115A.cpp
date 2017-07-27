#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back


using namespace std;

vector<vector<int> > v(2001);
int level[2001]={0};
int flag[2001]={0};
void bfs(int x)
{
	queue<int> q;
	q.push(x);
	int curr=x,pre;
	level[curr]=1;
	while(!q.empty())
	{
		curr = q.front();
		q.pop();
		pre = curr;
		flag[curr]=1;
		for(int k=0;k<v[curr].size();k++)
		{
			if(flag[v[curr][k]]==0)
			{
				flag[v[curr][k]]=1;
				level[v[curr][k]]=level[curr]+1;
				q.push(v[curr][k]);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,x;
	cin >> n;
	vector<int> head;
	for(int i=1;i<=n;i++)
	{
		cin >> x;
		if(x==-1)
		{
			head.pb(i);
		}
		else
		{
			v[x].pb(i);
		}
	}
	
	for(int i=0;i<head.size();i++)
	{
		bfs(head[i]);
	}
	int ans=0;
	sort(level+1,level+n+1);
	/*for(int i=0;i<n+1;i++)
	{
		cout << level[i] << " ";
	}
	cout << endl;*/
	for(int i=1;i<n+1;i++)
	{
		if(level[i]!=level[i-1])
		{
			//cout << i << endl;
			ans++;
		}
	}
	cout << ans;
}
