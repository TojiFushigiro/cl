
#include<stdio.h>
#include<string.h>

char input[100];
int i=0;
int error=0;

void E();
void T();
void F();

void E()
{
    T();

    if(error) return;

    if(input[i]=='+' || input[i]=='-')
    {
        i++;
        E();
    }
}

void T()
{
    F();

    if(error) return;

    if(input[i]=='*' || input[i]=='/')
    {
        i++;
        T();
    }
}

void F()
{
    if((input[i]>='a' && input[i]<='z') ||
       (input[i]>='A' && input[i]<='Z'))
    {
        i++;
    }
    else if(input[i]=='(')
    {
        i++;
        E();

        if(input[i]==')')
            i++;
        else
            error=1;
    }
    else
    {
        error=1;
    }
}

int main()
{
    printf("Enter the string:\n");
    scanf("%99s",input);

    E();

    if(input[i]=='\0' && error==0)
        printf("String accepted\n");
    else
        printf("String rejected\n");

    return 0;
}
