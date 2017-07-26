#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
	int k,j,i,l,arr1[26]={0},flag=1,m;
	scanf("%d",&k);
	char s[1001];
	scanf("%s",s);
	l=strlen(s);
	if(l%k!=0)
	{
		printf("-1");
	}
	else
	{	
		i=0;
		while(s[i]!='\0')
		{
			arr1[s[i]-97]++;
			i++;	
		}
		for(j=0;j<26;j++)
		{
			if(arr1[j]%k!=0)
			{
				printf("-1");
				flag=0;
				break;
			}
		}
		if(flag!=0)
		{
			for(i=0;i<k;i++)
			{	
				for(j=0;j<26;j++)
				{
					if(arr1[j]!=0)
					{	
						for(m=0;m<arr1[j]/k;m++)
						{
							printf("%c",j+97);
						}
					}
				}
			}
		}		
	}
}
