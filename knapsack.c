#include <stdio.h>
#include <stdlib.h>

// Global variables
int mat[50][50], w[50], p[50], Count;

// Function to return the maximum of two values
int Max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to solve the knapsack problem using dynamic programming
int knap(int n, int C)
{
    Count = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= C; j++)
        {
            Count++;
            if (i == 0 || j == 0)
            {
                Count--;
                mat[i][j] = 0;
            }
            else if (j < w[i])
                mat[i][j] = mat[i - 1][j];
            else
                mat[i][j] = Max(mat[i - 1][j], (p[i] + mat[i - 1][j - w[i]]));
        }
    }
    return mat[n][C];
}

// Function to test the knapsack implementation with user input
void tester()
{
    int n, C;
    printf("\nEnter the number of items: ");
    scanf("%d", &n);
    printf("\nEnter the weights and profits:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &w[i], &p[i]);

    printf("\nEnter the maximum capacity: ");
    scanf("%d", &C);

    printf("\nI  W  P\n");
    for (int i = 1; i <= n; i++)
        printf("%d  %d  %d\n", i, w[i], p[i]);

    printf("\nThe maximum profit is: %d\n", knap(n, C));

    printf("\nKnapsack Matrix:\n");
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= C; j++)
            printf("%d  ", mat[i][j]);
        printf("\n");
    }

    int j = C;
    printf("\nItems included in the knapsack: ");
    for (int i = n; i > 0 && j > 0; i--)
    {
        if (mat[i][j] != mat[i - 1][j])
        {
            printf("%d  ", i);
            j -= w[i];
        }
    }
    printf("\n");
}

// Function to generate random test cases and write results to a file
void plotter()
{
    FILE *f1;
    f1 = fopen("knap.txt", "w");
    int c;
    for (int i = 1; i <= 40; i += 4)
    {
        c = i + 3;
        for (int j = 1; j <= i; j++)
        {
            w[j] = rand() % i + 1; // Ensuring that weights are always positive
            p[j] = rand() % 100;
        }
        knap(i, c);
        fprintf(f1, "%d\t%d\n", i, Count);
    }
    fclose(f1);
    printf("\nPlotting completed and data written to 'knap.txt'.\n");
}

// Main function
int main()
{
    while (1)
    {
        int ch;
        printf("\nEnter 1 for tester, 2 for plotter, 3 to exit: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            tester();
            break;
        case 2:
            plotter();
            break;
        case 3:
            return 0;
        default:
            printf("\nInvalid input. Please try again.\n");
        }
    }
}
