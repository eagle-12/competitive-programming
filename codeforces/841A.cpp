#include <bits/stdc++.h>

#define ll      long long int
#define pb         push_back


using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	int arr[26]={0};
	for(int i=0;i<s.size();i++)
	{
		if(((int)s[i])<97)
		{
			arr[s[i]-'A']++;
		}
		else
		{
			arr[s[i]-'a']++;
		}
	}
	for(int i=0;i<26;i++)
	{
		if(arr[i]>k)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
