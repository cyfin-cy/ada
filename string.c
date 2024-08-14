#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int count = 0;
int stringmatching(char *text, char *pattern, int n, int m)
{
    count = 0;
    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;
        while (j < m)
        {
            count++;
            if (pattern[j] != text[i + j])
                break;
            j++;
        }
        if (j == m)
        {
            printf("THE PATTERN FOUND \n");
            return count;
        }
    }
    printf("THE PATTERN not found \n");
    return count;
}
int main()
{
    int m, n;
    char text[100], pattern[100];
    printf("ENTER THE PATTERN LENGTH\n");
    scanf("%d", &m);
    printf("ENTER THE PATTERN\n");
    getchar(); // Consume the newline character left in the input buffer
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0'; // Remove the newline character from the
    input
        printf("ENTER THE TEXT LENGTH\n");
    scanf("%d", &n);
    printf("ENTER THE TEXT\n");
    getchar(); // Consume the newline character left in the input buffer
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove the newline character from the input
    int comparisons = stringmatching(text, pattern, n, m);
    printf("Number of comparisons: %d\n", comparisons);
    return 0;
}
PLOTTER
// Program to perform analysis of brute force string matching
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count = 0;
int stringmatching(char *text, char *pattern, int n, int m)
{
    count = 0;
    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;
        while (j < m)
        {
            count++;
            if (pattern[j] != text[i + j])
                break;
            j++;
        }
        if (j == m)
        {
            return count;
        }
    }
    return count;
}
void ploter()
{
    FILE *f1 = fopen("stringbest.txt", "a");
    FILE *f2 = fopen("stringworst.txt", "a");
    FILE *f3 = fopen("stringavg.txt", "a");
    char *text = (char *)malloc(1000 * sizeof(char));
    char *pattern;
    for (int i = 0; i < 1000; i++)
        *(text + i) = 'a';
    int m, n;
    n = 1000;
    m = 10;
    while (m <= 1000)
    {
        pattern = (char *)malloc(m * sizeof(char));
        // For Best case
        for (int i = 0; i < m; i++)
            pattern[i] = 'a';
        count = 0;
        stringmatching(text, pattern, n, m);
        fprintf(f1, "%d\t%d\n", m, count); // printf("%d\t%d\n", m, count);
        count = 0;
        // For Worst case
        count = 0;
        pattern[m - 1] = 'b';
        stringmatching(text, pattern, n, m);
        fprintf(f2, "%d\t%d\n", m, count); // printf("%d\t%d\n", m, count);
        // For Average Case
        for (int i = 0; i < m; i++)
            pattern[i] = 97 + rand() % 3;
        count = 0;
        stringmatching(text, pattern, n, m);
        fprintf(f3, "%d\t%d\n", m, count); // printf("%d\t%d\n", m, count);
        // for(int i=0; i<m; i++)
        // printf("%c ",pattern[i]);
        // printf("\n");
        count = 0;
        free(pattern);
        if (m < 100)
            m = m + 10;
        else
            m = m + 100;
    }
}
void main()
{
    ploter();
}