#include <stdio.h>
#include <string.h>
int main()
{
	int n,i,j,res,max=0,temp1=0;
	scanf("%d",&n);
	char s[n][n+2],temp[n+2];
	int arr[2][n];
	for(i=0;i<n;i++)
	{
		scanf(" %[^\n]s",s[i]);
	}
	for(i=0;i<n;i++)
	{	
		temp1=0;	
		strcpy(temp,s[i]);
		for(j=0;j<n;j++)
		{
			if(strcmp(temp,s[j])==0)
			{
				temp1++;
			}
		}
		if(temp1>max)
		max=temp1;
	}
	printf("%d\n",max);
}
