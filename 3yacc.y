
%{
#include<stdio.h>
#include<stdlib.h>

int yylex();
void yyerror(char *s);
%}

%token NUMBER ID

%left '+' '-'
%left '*' '/'
%right UMINUS

%%

input:
    expr '\n' {printf("Valid arithmetic expr\n");}
    ;

expr:
      expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | '(' expr ')'
    | '-' expr %prec UMINUS
    | NUMBER
    | ID
    ;

%%

void yyerror(char *s)
{
    printf("Invalid arithmetic expr\n");
}

int main()
{
    printf("Enter an arithmetic expression: ");
    yyparse();
    return 0;
}
