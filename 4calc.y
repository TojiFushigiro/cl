
%{
#include<stdio.h>
#include<stdlib.h>

int yylex();
void yyerror(char *s);
%}

%token NUMBER

%left '+' '-'
%left '*' '/'

%%

input:
      | input line
      ;

line:
    expr '\n' {printf("result=%d\n",$1);}
    ;

expr:
      NUMBER       {$$=$1;}
    | expr '+' expr {$$=$1+$3;}
    | expr '-' expr {$$=$1-$3;}
    | expr '*' expr {$$=$1*$3;}
    | expr '/' expr
      {
          if($3==0)
          {
              printf("Division by zero error\n");
              $$=0;
          }
          else
          {
              $$=$1/$3;
          }
      }
    | '(' expr ')' {$$=$2;}
    ;

%%

void yyerror(char *s)
{
    printf("Invalid expression\n");
}

int main()
{
    printf("Enter arithmetic expression: ");
    yyparse();
    return 0;
}
