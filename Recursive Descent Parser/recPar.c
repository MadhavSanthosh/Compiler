/*Grammar L={S->aaAB,
A->aaA|ε,
B->bB|ε}*/
int ptr=0;char buff[10];
int A();
int B();
int S()
{	if(buff[ptr++]=='a')
		printf("Match found a\n");
	else
	{	printf("Error\n");
		return 0;
	}
	if(buff[ptr++]=='a')
		printf("Match found a\n");
	else
	{	printf("Error\n");
		return 0;
	}
	int c=A();
	if(c==0)
		return 0;
	c=B();
	return c;
	
}
int A()
{	if(buff[ptr]=='b'||buff[ptr]=='$')
	{	return 1;
	}
	if(buff[ptr++]=='a')
		printf("Match found a\n");
	else
	{	printf("Error\n");
		return 0;
	}
	if(buff[ptr++]=='a')
		printf("Match found a\n");
	else
	{	printf("Error\n");
		return 0;
	}
	int c=A();
	return c;
}
int B()
{	if(buff[ptr]=='$')
	{	return 1;
	}
	if(buff[ptr++]=='b')
		printf("Match found b\n");
	else
	{	printf("Error\n");
		return 0;
	}
	int c=B();
	return c;
}
int main()
{	printf("Enter input\n");
	scanf("%s",buff);
	int c=S();
	if(c==1)
		printf("Sucessfully parsed\n");
}

/*OUTPUT
Enter input
aab$
Match found a
Match found a
Match found b
Sucessfully parsed
*/