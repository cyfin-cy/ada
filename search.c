#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int linearSearch(int *a, int k, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (*(a + i) == k)
        {
            return i;
        }
    }
    return -1;
}
int binarySearch(int key, int *a, int high, int low)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2; // To avoid potential overflow
        if (*(a + mid) == key)
            return mid;
        else if (*(a + mid) > key)
            return binarySearch(key, a, mid - 1, low);
        else
            return binarySearch(key, a, high, mid + 1);
    }
    return -1;
}
int main()
{
    int arr[100];
    int n, key, r;
    for (;;)
    {
 printf("ENTER 1. TO LINEAR SEARCH\n2. TO BINARY SEARCH\n3. 
TO EXIT\n");
 int ch;
 scanf("%d", &ch);
 switch (ch) {
        case 1:
            printf("ENTER THE NUMBER OF ELEMENTS\n");
            scanf("%d", &n);
            printf("ENTER THE ELEMENTS OF THE ARRAY\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            printf("ENTER THE KEY ELEMENT\n");
            scanf("%d", &key);
            r = linearSearch(arr, key, n);
            if (r != -1)
            {
                printf("The element is present at the index %d\n", r);
            }
            else
            {
                printf("Element not found\n");
            }
            break;
        case 2:
            printf("ENTER THE NUMBER OF ELEMENTS\n");
            scanf("%d", &n);
            printf("ENTER THE ELEMENTS OF THE ARRAY\n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            printf("ENTER THE KEY ELEMENT\n");
            scanf("%d", &key);
            r = binarySearch(key, arr, n - 1, 0);
            if (r != -1)
            {
                printf("The element is present at the index %d\n", r);
            }
            else
            {
                printf("Element not found\n");
            }
            break;
        default:
            exit(0);
 }
    }
    return 0;
}
PLOTTER
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count;
int linearSearch(int *a, int k, int n)
{
    int i;
    count = 0;
    for (i = 0; i < n; i++)
    {
        count++;
        if (*(a + i) == k)
        {
            return count;
        }
    }
    return count;
}
int binarySearch(int key, int *a, int high, int low)
{
    int mid;
    count++;
    mid = (high + low) / 2;
    if (low > high)
        return count - 1;
    if (*(a + mid) == key)
        return count;
    else if (*(a + mid) > key)
        return binarySearch(key, a, mid - 1, low);
    else
        return binarySearch(key, a, high, mid + 1);
}
void plotter1()
{
    srand(time(NULL));
    int *arr;
    int n, key, r;
    FILE *f1, *f2, *f3;
    f1 = fopen("linearbest.txt", "a");
    f2 = fopen("linearavg.txt", "a");
    f3 = fopen("linearworst.txt", "a");
    n = 2;
    while (n <= 1024)
    {
        arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            *(arr + i) = 1;
        r = linearSearch(arr, 1, n);
        fprintf(f1, "%d\t%d\n", n, r);
        for (int i = 0; i < n; i++)
            *(arr + i) = rand() % n;
        key = rand() % n;
        r = linearSearch(arr, key, n);
        fprintf(f2, "%d\t%d\n", n, r);

        for (int i = 0; i < n; i++)
            *(arr + i) = 0;
        r = linearSearch(arr, 1, n);
        fprintf(f3, "%d\t%d\n", n, r);
        n = n * 2;
        free(arr);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}
void plotter2()
{
    srand(time(NULL));
    int *arr;
    int n, key, r;
    FILE *f1, *f2, *f3;
    f1 = fopen("binarybest.txt", "a");
    f2 = fopen("binaryavg.txt", "a");
    f3 = fopen("binaryworst.txt", "a");
    n = 2;
    while (n <= 1024)
    {
        arr = (int *)malloc(n * sizeof(int));
        // best case
        for (int i = 0; i < n; i++)
            *(arr + i) = 1;
        int mid = (n - 1) / 2;
        *(arr + mid) = 0;
        count = 0;
        r = binarySearch(0, arr, n - 1, 0);
        fprintf(f1, "%d\t%d\n", n, r);
        // printf("%d\t%d\n", n, count);

        // avgcase
        for (int i = 0; i < n; i++)
            *(arr + i) = rand() % n;
        key = rand() % n + 1;
        count = 0;
        r = binarySearch(-1, arr, n - 1, 0);
        fprintf(f2, "%d\t%d\n", n, r);

        // printf("%d\t%d\n", n, count);

        // worst case
        for (int i = 0; i < n; i++)
            *(arr + i) = 0;
        count = 0;
        r = binarySearch(1, arr, n - 1, 0);
        fprintf(f3, "%d %d\n", n, r);

        // printf("%d\t%d\n", n, count);
        n = n * 2;
        free(arr);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}
void main()
{
    plotter1();
    plotter2();
}