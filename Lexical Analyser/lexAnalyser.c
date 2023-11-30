//Lexical Analyser
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
int state=1;int ptr,cptr;int c=0;
char table[10][20];char idBuff[10];
void s1(char forward)
{	if(forward=='i')
		state=7;
	else if(forward=='f')
		state=13;
	else if(forward=='v')
		state=17;
	else if(forward=='>')
		state=21;
	else if(forward=='<')
		state=23;
	else if(forward=='=')
		state=25;
	else if(isdigit(forward))
		state=4;
	else if(forward=='\n' || forward=='\t')
		state=1;
	else
		state=2;
}
void s2(char forward)
{	if(isalnum(forward))
		state=2;
	else if(forward==' ')
	if(forward==' ')
	{	
		state=1;
		printf("Identifier\n");
		idBuff[cptr]='\0';
		//printf("identifier is %s\n",idBuff);
		int flag=0;
		for(int i=0;i<=c;i++)
		{	//printf("%s,%s\n",table[i],idBuff);
			if(strcmp(table[i],idBuff)==0)
				{flag=1;break;}
		}
		if(flag==0)
		{
			for(int i=0;i<=cptr+1;i++)
			{	table[c][i]=idBuff[i];
			}
			//printf("%s\n",table[c]);
			c++;
		}
		cptr=0;
	}
}
void s3(char forward)
{
}
void s4(char forward)
{	if(isdigit(forward))
		state=4;
	else if(forward=='.')
		state=5;
	else if(forward==' ')
		{state=1;
		printf("Number\n");
		cptr=0;}
}
void s5(char forward)
{	if(isdigit(forward))
		state=5;
	else if(forward==' ')
	{	state=1;
		printf("Number\n");
		cptr=0;
	}
}
void s6(char forward)
{
}
void s7(char forward)
{	if(forward=='n')
		state=8;
	else if(forward=='f')
		state==11;
	else
		state=2;
}
void s8(char forward)
{	if(forward=='t')
		state=9;
	else
		state=2;
}
void s9(char forward)
{	if(forward==' ')
	{	state=1;
		printf("int\n");
		cptr=0;
	}
	else
		state=2;
}
void s10(char forward)
{
}
void s11(char forward)
{	if(forward==' ')
	{	state=1;
		printf("if\n");
		cptr=0;
	}
	else
		state=2;
}
void s12(char forward)
{
}
void s13(char forward)
{	if(forward=='o')
		state=14;
	else
		state=2;
}
void s14(char forward)
{	if(forward=='r')
		state=15;
	else
		state=2;
}
void s15(char forward)
{	if(forward==' ')
	{	state=1;
		printf("for\n");
		cptr=0;
	}
	else
		state=2;
}
void s16(char forward)
{
}
void s17(char forward)
{	if(forward=='o')
		state=18;
	else
		state=2;
}
void s18(char forward)
{	if(forward=='i')
		state=19;
	else
		state=2;
}
void s19(char forward)
{	if(forward=='d')
		state=20;
	else
		state=2;
}
void s20(char forward)
{	if(forward==' ')
	{	state=1;
		printf("void\n");
		cptr=0;
	}
	else
		state=2;
}
void s21(char forward)
{	if(forward==' ')
	{	state=1;
		printf("Greater than\n");
		cptr=0;
	}
	else if(forward=='=')
		state=22;
}
void s22(char forward)
{	if(forward==' ')
	{	state=1;
		printf("Greater than equals to\n");
		cptr=0;
	}
}
void s23(char forward)
{	if(forward==' ')
	{	state=1;
		cptr=0;
		printf("Less than\n");
	}
	else if(forward=='=')
		state=24;
}
void s24(char forward)
{	if(forward==' ')
	{	state=1;
		printf("Less than equals to\n");
		cptr=0;
	}
}
void s25(char forward)
{	if(forward==' ')
	{	state=1;
		printf("Equals to\n");
		cptr=0;
	}
}


void main()
{	
	FILE *fp1;
	fp1=fopen("input.txt","r");
	while(!feof(fp1))
	{	char buffer[100];
		fgets(buffer,100,fp1);
		char ch=buffer[0];
		ptr=0;
		printf("%s",buffer);
		while(ch!='\0')
		{	printf("%c",ch);
			idBuff[cptr++]=ch;		
			if(ch!=';')
			{	
			switch(state)
			{	case 1:s1(ch);break;
				case 2:s2(ch);break;
				case 3:s3(ch);break;
				case 4:s4(ch);break;
				case 5:s5(ch);break;
				case 6:s6(ch);break;
				case 7:s7(ch);break;
				case 8:s8(ch);break;
				case 9:s9(ch);break;
				case 10:s10(ch);break;
				case 11:s11(ch);break;
				case 12:s12(ch);break;
				case 13:s13(ch);break;
				case 14:s14(ch);break;
				case 15:s15(ch);break;
				case 16:s16(ch);break;
				case 17:s17(ch);break;
				case 18:s18(ch);break;
				case 19:s19(ch);break;
				case 20:s20(ch);break;
				case 21:s21(ch);break;
				case 22:s22(ch);break;
				case 23:s23(ch);break;
				case 24:s24(ch);break;
				case 25:s25(ch);break;
				default : break;
			}
			}
			//printf("%d",state);
			ptr++;
			ch=buffer[ptr];
		}
	}
	fclose(fp1);
	for(int i=0;i<c;i++)
	{	printf("%s id%d\n",table[i],i);
	}
}

/*OUTPUT
int num1 = 23 ;
int int
num1 Identifier
= Equals to
23 Number
;
int num2 = 78 ;
int int
num2 Identifier
= Equals to
78 Number
;
int a = num1 ;
int int
a Identifier
= Equals to
num1 Identifier
;
int a = num1 ;
int int
a Identifier
= Equals to
num1 Identifier
;
num1  id0
num2  id1
a  id2
*/