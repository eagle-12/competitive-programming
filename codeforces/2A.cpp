#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back


using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	map<string,int> game;
	int n;
	cin >> n;
	vector<pair<string,int> > v(n);
	int x;
	string s,name;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		cin >> s >> x;
		v[i].first = s;
		v[i].second = x;
		if(game.find(s)==game.end())
		{
			game[s]=x;
		}
		else
		{
			game[s]+=x;
		}
	}
	int l=game.size();
	map<string,int>::iterator itr;
	//itr = game.begin();
	//vector<string> n;
	for(itr=game.begin();itr!=game.end();itr++)
	{
		//itr = itr+i;
		ans = max(ans,itr->second);
	}
	//cout << ans;
	//itr = game.begin();
	map<string,int> games;
	for(int i=0;i<n;i++)
	{
		s = v[i].first;
		x = v[i].second;
		if(games.find(s)==games.end())
		{
			games[s]=x;
			if(games[s]>=ans && game[s]==ans)
			{
				cout << s << endl;
				return 0;
			}
		}
		else
		{
			games[s]+=x;
			if(games[s]>=ans && game[s]==ans)
			{
				cout << s << endl;
				return 0;
			}
		}
	}	
}
