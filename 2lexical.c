
%{
    #include<stdio.h>
%}

%%
int|float|char|if|else|while|return {printf("%s : Keyword\n",yytext);}
[0-9]+ {printf("%s : Integer\n",yytext);}
[a-zA-Z_][a-zA-Z0-9_]* {printf("%s : Identifier\n",yytext);}
[+*/=-] {printf("%s : Operator\n",yytext);}
[(){};,] {printf("%s : Special Symbol\n",yytext);}
[ \t\n]+ ;
. {printf("%s : unknown\n",yytext);}
%%

int main()
{
    FILE *fp;

    fp=fopen("input.txt","r");

    if(fp==NULL)
    {
        printf("Error opening file.");
        return 1;
    }

    yyin=fp;

    printf("TOKEN\t\tLEXEME\n");
    printf("----------------------\n");

    yylex();

    fclose(fp);
    return 0;
}

int yywrap()
{
    return 1;
}
