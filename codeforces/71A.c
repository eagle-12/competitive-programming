#include <stdio.h>
#include <string.h>
int main()
{
	int n,i,l;
	char s[101];
	scanf("%d ",&n);
	for(i=0;i<n;i++)
	{
		scanf(" %s",s);
		l=strlen(s);
		if(l<=10)
		{
			printf("%s\n",s);
		}
		else
		{
			printf("%c",s[0]);
			printf("%d",l-2);
			printf("%c",s[l-1]);
			printf("\n");
		}
			
	}
	return 0;
}
