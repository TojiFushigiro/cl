#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *key[] = {"int", "float", "char", "if", "else",
               "while", "for", "return", "void", "double"};

int main()
{
    FILE *fp;
    char str[50];
    int ch, i, j;

    fp = fopen("input.c", "r");

    if (fp == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (isspace(ch))
            continue;

        if (isalpha(ch) || ch == '_')
        {
            i = 0;

            do
            {
                if (i < 49)
                    str[i++] = ch;

                ch = fgetc(fp);

            } while (ch != EOF && (isalnum(ch) || ch == '_'));

            str[i] = '\0';

            for (j = 0; j < 10; j++)
            {
                if (strcmp(str, key[j]) == 0)
                    break;
            }

            if (j < 10)
                printf("Keyword: %s\n", str);
            else
                printf("Identifier: %s\n", str);

            if (ch != EOF)
                ungetc(ch, fp);
        }

        else if (isdigit(ch))
        {
            printf("Number: %c", ch);

            while ((ch = fgetc(fp)) != EOF && isdigit(ch))
                putchar(ch);

            printf("\n");

            if (ch != EOF)
                ungetc(ch, fp);
        }

        else if (strchr("+-*/=<>!", ch))
            printf("Operator: %c\n", ch);

        else if (strchr("(){}[],;#", ch))
            printf("Symbol: %c\n", ch);

        else
            printf("Unknown: %c\n", ch);
    }

    fclose(fp);
    return 0;
}