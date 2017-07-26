#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	string s1,s2,s3;
	cin >> s1;
	cin >> s2;
	cin >> s3;
	int ans[4][4]={0};
	if(s1[1]=='>')
	{
		ans[s1[0]-'A'+1][s1[2]-'A'+1]=1;
		ans[s1[2]-'A'+1][s1[0]-'A'+1]=0;
	}
	else
	{
		ans[s1[0]-'A'+1][s1[2]-'A'+1]=0;
		ans[s1[2]-'A'+1][s1[0]-'A'+1]=1;		
	}
	if(s2[1]=='>')
	{
		ans[s2[0]-'A'+1][s2[2]-'A'+1]=1;
		ans[s2[2]-'A'+1][s2[0]-'A'+1]=0;
	}
	else
	{
		ans[s2[0]-'A'+1][s2[2]-'A'+1]=0;
		ans[s2[2]-'A'+1][s2[0]-'A'+1]=1;		
	}
	if(s3[1]=='>')
	{
		ans[s3[0]-'A'+1][s3[2]-'A'+1]=1;
		ans[s3[2]-'A'+1][s3[0]-'A'+1]=0;
	}
	else
	{
		ans[s3[0]-'A'+1][s3[2]-'A'+1]=0;
		ans[s3[2]-'A'+1][s3[0]-'A'+1]=1;		
	}
	int ct1 = ans[1][1]+ans[1][2]+ans[1][3];
	int ct2 = ans[2][1]+ans[2][2]+ans[2][3];
	int ct3 = ans[3][1]+ans[3][2]+ans[3][3];
	if(ct1>ct2)
	{
		if(ct1>ct3)
		{
			if(ct2>ct3)
			{
				cout << "CBA";
			}
			else if(ct2<ct3)
			{
				cout << "BCA";
			}
		}
		else if(ct1<ct3)
		{
			cout << "BAC";
		}
	}
	else if(ct1<ct2)
	{
		if(ct3>ct2)
		{
			cout << "ABC";
		}
		else if(ct3<ct2)
		{
			if(ct3>ct1)
			{
				cout << "ACB";
			}
			else if(ct3<ct1)
			{
				cout << "CAB";
			}
		}
	}
	else
	{
		cout << "Impossible";
	}
}
