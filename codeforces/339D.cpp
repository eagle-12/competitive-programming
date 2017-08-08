#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cmath>
using namespace std;


#define ll long long int

ll tree[1000000];

void build(int node,int start,int end,ll a[],int op)
{
	if(start==end)
	{
		tree[node]=a[start];
	}
	else
	{
		int mid=(start+end)/2;
		build(2*node+1,start,mid,a,1-op);
		build(2*node+2,mid+1,end,a,1-op);
		if(op==1)
		{
			tree[node]=tree[node*2+1]^tree[2*node+2];
		}
		else
		{
			tree[node]=tree[2*node+1]|tree[2*node+2];
		}
	}
}

void update(ll a[],int node,int start,int end,ll i,ll key,int op)
{
	if(i<start || i>end)
	{
		return;
	}
	if(start==end)
	{
		tree[node]=key;
		a[i]=key;
	}
	else
	{
		int mid=(start+end)/2;
		update(a,2*node+1,start,mid,i,key,1-op);
		update(a,2*node+2,mid+1,end,i,key,1-op);
		if(op==1)
		{
			tree[node]=tree[node*2+1]^tree[2*node+2];
		}
		else
		{
			tree[node]=tree[2*node+1]|tree[2*node+2];
		}
	}
}

int main()
{
	ll n,m;
	cin >> n >> m;
	ll idx=pow(2,n);
	ll arr[idx];
	for(int i=0;i<idx;i++)
	{
		cin >> arr[i];
	}
	int ele;
	if(n%2==0)
	{
		ele=1;
	}
	else
	{
		ele=0;
	}
	int x,y;
	build(0,0,idx-1,arr,ele);
	for(int i=0;i<m;i++)
	{
		cin >> x >> y;
		update(arr,0,0,idx-1,x-1,y,ele);
		cout << tree[0] << endl;
	}
}
