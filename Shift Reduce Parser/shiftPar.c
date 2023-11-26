#include <stdio.h>
#include <string.h>
void main()
{	char str[20],S[20],grm[10][10];
	int n;int sp=0,p=0;
	printf("Enter number of productions in grammer\n");
	scanf("%d",&n);
	printf("Enter the productions\n");
	for(int i=0;i<n;i++)
	{	scanf("%s",grm[i]);
	}
	printf("Enter string\n");
	scanf("%s",str);
	S[0]='$';
	printf("Stack\tInput\tAction\n");
	while(str[p]!='$')
	{	int flag=0;
		for(int i=0;i<n;i++)
		{	char prod[10];int j=3,c=0;
			while(grm[i][j]!='\0')
			{	prod[c++]=grm[i][j++];
			}
			prod[c]='\0';
			char stch[10];
			for(int k=0;k<c;k++)
			{	if(sp-c+k+1>-1)
					stch[k]=S[sp-c+k+1];
			}
			stch[c]='\0';
			if(strcmp(prod,stch)==0)
			{	flag=1;
				sp=sp-c+1;
				S[sp]=grm[i][0];
				printf("%s\t%s\tReduce\n");
				break;
			}
		}
		if(flag==0)
		{	sp++;
			S[sp]=str[p++];
			printf("Shift\n");
		}
	}
	if(S[1]=='S')
		printf("Parsed sucessfully\n");
	else
		printf("String not parsed\n");
}