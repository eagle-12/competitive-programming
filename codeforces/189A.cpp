#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,a,b,c,x,y,z;
	cin >> n >> a >> b >> c;
	/*x = min(a,min(b,c));
	z = max(a,max(b,c));
	if(x==a && z==b)
	{
		y = c;
	}
	else if(x==a && z==c)
	{
		y = b;
	}
	else
	{
		y = a;
	}*/
	if(a<b)
	{
		if(a<c)
		{
			x = a;
			if(b<c)
			{
				y = b;
				z = c;	
			}
			else
			{
				y = c;
				z = b;
			}
		}
		else
		{
			x = c;
			y = a;
			z = b;
		}
	}
	else
	{
		if(a<c)
		{
			x = b;
			y = a;
			z = c;
		}
		else
		{
			if(c<b)
			{
				x = c;
				y = b;
				z = a;
			}
			else
			{
				x = b;
				y = c;
				z = a;
			}
		}
	}
	//cout << x << y << z << endl;
	if(x==y && x==z)
	{
		if(n%x==0)
		{
			cout << n/x;
			return 0;
		}
		else
		{
			cout << 0;
			return 0;
		}
	}
	int arr1[4][n+1];
	for(int i=0;i<4;i++)
	{
		arr1[i][0] = 1;
	}
	for(int i=1;i<n+1;i++)
	{
		arr1[0][i] = 0;
	}
	for(int i=1;i<n+1;i++)
	{
		if(i%x==0)
		{
			arr1[1][i] = i/x;
		}
		else
		{
			arr1[1][i] = 0;
		}
	}
	for(int i=1;i<n+1;i++)
	{
		if(i>y && arr1[2][i-y]!=0)
		{
			arr1[2][i] = max(arr1[1][i],1 + arr1[2][i-y]);
		}
		else if(i==y)
		{
			arr1[2][i] = max(arr1[1][i],1);
		}
		else
		{
			arr1[2][i] = arr1[1][i];
		}
	}
	for(int i=1;i<n+1;i++)
	{
		if(i>z && arr1[3][i-z]!=0)
		{
			arr1[3][i] = max(arr1[2][i],1 + arr1[3][i-z]);
		}
		else if(i==z)
		{
			arr1[3][i] = max(arr1[2][i],1);
		}
		else
		{
			arr1[3][i] = arr1[2][i];
		}
	}
	cout << arr1[3][n];
}
