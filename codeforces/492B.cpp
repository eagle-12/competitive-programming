#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,l;
	cin >> n >> l;
	int dis[n];
	for(int i=0;i<n;i++)
	{
		cin >> dis[i];
	}
	sort(dis,dis+n);
	double ans = (double)max(dis[0],l-dis[n-1]);
	for(int i=0;i<n-1;i++)
	{
		ans = max(ans,(double)(dis[i+1]-dis[i])/2);
	}
	cout << fixed << setprecision(10) << ans;
	//printf("%.10lf",ans);
}
