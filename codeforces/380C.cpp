#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

string s;

pair<ll,pair<ll,ll> > tree[4000000];

void build(ll node,ll si,ll ed)
{
	if(si==ed)
	{
		if(s[si]=='(')
		{
			tree[node].se.fi=1;
		}
		else
		{
			tree[node].se.se=1;
		}
		return;
	}
	int mid=(si+ed)/2;
	build(2*node+1,si,mid);
	build(2*node+2,mid+1,ed);
	int temp = min(tree[2*node+1].se.fi,tree[2*node+2].se.se);
	tree[node].fi=tree[2*node+1].fi + tree[2*node+2].fi + temp;
	tree[node].se.fi=tree[2*node+1].se.fi+tree[2*node+2].se.fi-temp;
	tree[node].se.se=tree[2*node+1].se.se+tree[2*node+2].se.se-temp;
}

pair<ll,pair<ll,ll> > query(int node,int st,int ed,int qs,int qe)
{
	if(qs>qe)
	{
		return mp(0,mp(0,0));
	}
	if(qs>ed || st>qe)
	{
		return mp(0,mp(0,0));
	}
	if(qs<=st && qe>=ed)
	{
		return tree[node];
	}
	int mid=(st+ed)/2;
	pair<ll,pair<ll,ll> > lf=query(2*node+1,st,mid,qs,qe);
	pair<ll,pair<ll,ll> > rh=query(2*node+2,mid+1,ed,qs,qe);
	int temp=min(lf.se.fi,rh.se.se);
	pair<ll,pair<ll,ll> > res;
	res.fi=lf.fi+rh.fi+temp;
	res.se.fi=lf.se.fi+rh.se.fi-temp;
	res.se.se=lf.se.se+rh.se.se-temp;
	return res;	
}

int main ()
{
	cin >> s;
	int m;
	cin >> m;
	int x=s.size();
	build(0,0,x-1);
	int l,r;
	for(int i=0;i<m;i++)
	{
		cin >> l >> r;
		cout << 2*query(0,0,x-1,l-1,r-1).fi << endl;
	}
}
