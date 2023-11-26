%{
#include <stdio.h>
%}
%token NUMBER ID
%left '+' '-'
%left '*' '/'
%left '%'
%right '^'
%left '(' ')'
%%
E : T {printf("Result = %d\n",$$);
	return 0;
	}
	
T :
	T '+' T { $$ = $1 + $3; }
	| T '-' T { $$ = $1 - $3; }
	| T '*' T { $$ = $1 * $3; }
	| T '/' T { $$ = $1 / $3; }
	| T '^' T { int t=$1;
			for(int i=1;i<$3;i++)
				t*=$1;
			$$=t;}
	| T '%' T { $$ = $1 / $3; }
	| '-' NUMBER { $$ = -$2; }
	| '-' ID { $$ = -$2; }
	| '('T')'{ $$ = $2; }
	| NUMBER { $$ = $1;}
	| ID {$$ = $1; }
%%

int main(){
	printf("Enter the expression\n");
	yyparse();
}

int yyerror(char* s) {
	printf("\nExpression is invalid\n");
}
