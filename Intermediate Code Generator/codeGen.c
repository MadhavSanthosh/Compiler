#include<stdio.h>
#include<string.h>
#include<ctype.h>

char input[100];
int ip=0;
char postfix[100];
int pi=0;
char stack[10];
int top=-1;
char ti ='1';

void push(char c){
	stack[++top]=c;
}

char pop(){
	return stack[top--]; 
}
char topfn(){
	return stack[top];
}

int prec(char c){
      switch(c){
 	case'(': return 0;
 	case'/': 
 	case'*': return 3;
 	case'+':
 	case'-': return 2;
 	case')': return 1;
 	case'#': return 4;
 }
 return -1;
}

int isop(char c){
	return prec(c) !=-1;
}

int main(){
 	printf("Enter Expression\n");
 	scanf("%s",input);
 	int len =strlen(input);
 	input[len++]=')';
  	for(int i=0;i<len;i++){
  		if(input[i]=='-' && (input[i-1]=='(' || i==0)){
      			input[i]='#';
        	}
 	}
 	push('(');
 	while(ip<len){
 		char ic = input[ip];
 		if(isop(ic)){
 			while(ic!='(' && top>-1 && prec(ic)<= prec(topfn())){
 				char c =pop();
 				postfix[pi++]=c;
 			}
 			ic==')' ? pop():push(ic);
 		}
 		else
 			postfix[pi++]=ic;
 		ip++;
 	}
 	int ci=0;

 	printf("\nIntermediate Code: \n");
 	while(ci<pi){
  		char pc =postfix[ci];
  		if (pc=='#'){
  			char a=pop();
  			printf("t%c=",ti);
  			printf("(UNARY-)");
  			isdigit(a)? printf("t%c",a):printf("%c",a);
   			printf("\n");
   			push(ti);
   			ti++;
    		}
   		else { 
  			if(isop(pc)){
  				char b=pop();
  				char a=pop();
  				printf("t%c=",ti);
  				isdigit(a)? printf("t%c",a):printf("%c",a);
  				printf("%c",pc);
  				isdigit(b)? printf("t%c",b):printf("%c",b);
   				printf("\n");
   				push(ti);
   				ti++;
  			}
  			else
    				push(pc);
  		}
  		ci++;
  	}
 	return 0;
}

/*OUTPUT
Enter Expression
a+b*c

Intermediate Code: 
t1=b*c
t2=a+t1
*/