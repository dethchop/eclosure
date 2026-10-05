#include <stdio.h>

#define MAX 20

int n;                         
int epsilon[MAX][MAX];         
int visited[MAX];


void epsilonClosure(int state)
{
    int i;

    visited[state] = 1;
    printf("q%d ", state);

    for (i = 0; i < n; i++)
    {
        if (epsilon[state][i] && !visited[i])
        {
            epsilonClosure(i);
        }
    }
}

int main()
{
    int i, j;

    printf("Enter the number of states: ");
    scanf("%d", &n);

    printf("\nEnter the epsilon transition matrix (0 or 1):\n");
    printf("(If there is an epsilon transition from qi to qj, enter 1, else 0)\n\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &epsilon[i][j]);
        }
    }

    printf("\nEpsilon Closures:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            visited[j] = 0;

        printf("ε-closure(q%d) = { ", i);
        epsilonClosure(i);
        printf("}\n");
    }

    return 0;
}
