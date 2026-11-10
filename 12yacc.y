%{
    #include<stdio.h>
    int yylex();
    int yyerror(char *);
%}

%token ID
%%
input: 
    ID '\n' {printf("Valid identifier\n");return 0;}
    ;
%%

int main()
{
printf("Enter identifier: ");
yyparse();
return 0;
}

int yyerror(char *s)
{
    printf("Invalid identifier\n");
    return 0;
}

