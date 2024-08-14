#include <stdio.h>
int graph[40][40], n, count = 0;
void createGraph()
{
    printf("No. of vertices>> ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
}
void main()
{
    createGraph();
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (graph[i][k] == 1)
            {
                for (int j = 0; j < n; j++)
                {
                    count++;
                    if (graph[k][j] == 1)
                    {
                        graph[i][j] = 1;
                    }
                }
            }
        }
    }
    printf("Applying Warshall's Algorithm\n");
    printf("Transitive Closure Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("Operation Count: %d\n", count);
}
Plotter
/* program to implement the Warshall's Algorithm*/
#include <stdio.h>
#include <stdlib.h>
    int graph[100][100];
int counter = 0;
void warshall(int n)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (graph[i][k] != 0)
            {
                for (int j = 1; j <= n; j++)
                { // graph[i][j] = (graph[i][k] && graph[k][j]));
                    graph[i][j] = (graph[i][j] || (graph[i][k] && graph[k][j]));
                    counter++;
                }
            }
        }
    }
}
void ploter(int c)
{
    FILE *f1 = fopen("warshalbest.txt", "a");
    FILE *f2 = fopen("warshallworst.txt", "a");
    for (int i = 1; i <= 10; i++)
    {
        int n = i;
        if (c == 1)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i != j)
                    {
                        graph[i][j] = 1;
                    }
                    else
                        graph[i][j] = 0;
                }
            }
        }
        if (c == 0)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                    graph[i][j] = 0;
            }
            for (int i = 1; i < n; i++)
            {
                graph[i][i + 1] = 1;
            }
            graph[n][1] = 1;
        }
        counter = 0;
        warshall(n);
        if (c == 0)
            fprintf(f1, "%d\t%d\n", n, counter);
        else
            fprintf(f2, "%d\t%d\n", n, counter);
    }
    fclose(f1);
    fclose(f2);
}
void main()
{
    for (int i = 0; i < 2; i++)
        ploter(i);
    printf("the graph is plotted\n");
}