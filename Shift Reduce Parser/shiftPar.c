#include <stdio.h>
#include <string.h>
#include <stdbool.h>
struct prod{
char lhs;
char rhs[10];
}gram[100];
int n;
char str[20],stk[20];
char *ip = str;
int sp=0;
bool present(int x){
	char stTop[10];int count=0;
	int size=strlen(gram[x].rhs);
	if(size>sp)
		return false;
	for(int i=0;i<size;i++)
	{	stTop[count++]=stk[sp-size+i+1];
	}
	stTop[count]='\0';
	if(strcmp(stTop,gram[x].rhs)==0)
	{	sp-=size;
		stk[++sp]=gram[x].lhs;
		stk[sp+1]='\0';
		return true;
	}
	else
		return false;
}
void main(){
	printf("Enter number of productions in grammer\n");
	scanf("%d",&n);
	printf("Enter the productions\n");
	for(int i=0;i<n;i++)
	{	char temp[10];
		scanf("%s",temp);
		gram[i].lhs=temp[0];
		int count=0;
		for(int j=3;j<strlen(temp);j++)
			gram[i].rhs[count++]=temp[j];
		gram[i].rhs[count]='\0';
	}
	printf("Enter string\n");
	scanf("%s",str);
	stk[0]='$';stk[1]='\0';
	printf("Stack\tInput\tAction\n");
	while(1)
	{	printf("%s\t%s",stk,ip);
		if(stk[sp]==gram[0].lhs && *ip=='$' && sp==1)
		{	printf("\nString parsed sucessfully\n");
			break;
		}
		bool flag=true;
		for(int i=0;i<n;i++)
		{	if(present(i))
			{	printf("\tReduce\n");
				flag=false;
				break;
			}
		}
		bool shifted=false;
		if(flag && !(*ip=='$'))
		{	stk[++sp]=*ip;
			ip++;
			shifted=true;
			printf("\tShift\n");
		}
		if(flag && !shifted)
		{	printf("String cannot be parsed\n");
		}
	}
}

/*OUTPUT
Enter number of productions in grammer
4
Enter the productions
S->S+S
S->S-S
S->(S)
S->a
Enter string
a+a$
Stack	Input	Action
$	a+a$	Shift
$a	+a$	Reduce
$S	+a$	Shift
$S+	a$	Shift
$S+a	$	Reduce
$S+S	$	Reduce
$S	$
String parsed sucessfully
*/