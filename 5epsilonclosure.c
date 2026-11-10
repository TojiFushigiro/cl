#include<stdio.h>
int n;
int e[20][20];
int visited[20];

void epsilonClosure(int state)
{
    int i;
    
    visited[state]=1;
    printf("q%d",state);

    for(i=0;i<n;i++)
    {
        if(e[state][i] && !visited[i])
        {
            epsilonClosure(i);
        }
    }
}

int main()
{
int i,j;
printf("Enter no of states: ");
scanf("%d",&n);

printf("enter epsilon transition matrix: \n");

for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        scanf("%d",&e[i][j]);
    }
}

printf("\nEpsilon closures:\n");

for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        visited[j]=0;
    }
    printf("epsilon closure(q%d)={",i);
    epsilonClosure(i);
    printf("}\n");
}
return 0;

}