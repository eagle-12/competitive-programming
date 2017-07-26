#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
	char s[101],l;
	fgets(s,101,stdin);
	int i=0;
	while(s[i]!='\0'&&s[i]!='\n')
	{	
		l=tolower(s[i]);
		if(l=='a'||l=='e'||l=='i'||l=='o'||l=='u'||l=='y')
		{
			i++;
			continue;
		}
		else
		{
			printf(".");
			printf("%c",l);
			i++;
		}
	}
}
