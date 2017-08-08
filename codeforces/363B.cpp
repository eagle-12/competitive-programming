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
	int n,k,sum=0;
	cin >> n >> k;
	int arr[n];
	vector<pair<int,int> > ans;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		if(i<k)
		{
			sum+=arr[i];
		}
	}
	int idx=0;
	//prev=sum;
	ans.push_back(make_pair(sum,0));
	idx=0;
	for(int i=k;i<n;i++)
	{
		ans.push_back(make_pair((ans[idx].first-arr[i-k]+arr[i]),ans[idx].second+1));
		idx++;
	}
	sort(ans.begin(),ans.end());
	cout << ans[0].second+1 << endl;
}
