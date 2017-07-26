#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
	int n,m,j,i,l1,l2,l;
	scanf("%d %d",&n,&m);
	char arr[2*m][11];
	char arr1[n][11];
	for(i=0;i<2*m;i++)
	{
		scanf("%s",arr[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%s",arr1[i]);
		for(j=0;j<2*m;j++)
		{
			l=strcmp(arr1[i],arr[j]);
			if(l==0)
			{
				break;
			}
		}
		if(j%2==0)
		{
			l1=strlen(arr[j]);
			l2=strlen(arr[j+1]);
			if(l1>l2)
			{
				printf("%s",arr[j+1]);
				if(i!=n-1)
				{
					printf(" ");
				}
			}
			else
			{
				printf("%s",arr[j]);
				if(i!=n-1)
				{
					printf(" ");
				}
			}

		}
		else
		{
			l1=strlen(arr[j]);
			l2=strlen(arr[j-1]);
			if(l1>l2)
			{
				printf("%s",arr[j-1]);
				if(i!=n-1)
				{
					printf(" ");
				}
			}
			else
			{
				printf("%s",arr[j]);
				if(i!=n-1)
				{
					printf(" ");
				}
			}	
		}
	}
}
