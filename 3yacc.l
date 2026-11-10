
%{
#include "y.tab.h"
%}

%%

[0-9]+                  {return NUMBER;}
[a-zA-Z_][a-zA-Z0-9_]*  {return ID;}
[ \t]+                  ;
"+"                     {return '+';}
"-"                     {return '-';}
"*"                     {return '*';}
"/"                     {return '/';}
"("                     {return '(';}
")"                     {return ')';}
\n                      {return '\n';}
.                       {return yytext[0];}

%%

int yywrap()
{
    return 1;
}
