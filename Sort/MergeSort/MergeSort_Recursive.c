#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define maxSize 10
#define numSize 100

int *list, length;

void RandomList();
void MergeSort(int n, int S[]);
void Merge(int h, int m, int A[], int B[], int S[]);

int main()
{
    RandomList();
    MergeSort(length, list);
    printf("\nAfter sort:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", list[i]);
    }
}
void RandomList()
{
    srand(time(NULL));
    length = (rand() % maxSize) + 1;

    printf("Size: %d\n", length);

    list = malloc(length * sizeof(int));

    for (int i = 0; i < length; i++)
    {
        list[i] = (rand() % numSize) + 1;
    }

    printf("Before sort:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
}

void MergeSort(int n, int S[])
{

    if (n > 1)
    {
        int h = n / 2; // 分成兩邊，size 大小分別為 h, m
        int m = n - h;
        int A[h], B[m]; // A, B 陣列儲存兩邊的陣列

        for (int i = 0; i < h; i++)
        {
            A[i] = S[i];
        }
        for (int i = h; i < n; i++)
        {
            B[i - h] = S[i];
        }

        MergeSort(h, A);
        MergeSort(m, B);

        Merge(h, m, A, B, S); // 將A, B 合併為 S
    }
}

void Merge(int h, int m, int A[], int B[], int S[])
{

    int i = 0, j = 0, k = 0;

    while (i < h && j < m)
    {
        if (A[i] < B[j])
        {
            S[k] = A[i];
            i++;
        }
        else
        {
            S[k] = B[j];
            j++;
        }
        k++;
    }

    if (i < h)
    {
        do
        {
            S[k] = A[i];
            i++;
            k++;
        } while (i < h);
    }
    else
    {
        do
        {
            S[k] = B[j];
            j++;
            k++;
        } while (j < m);
    }
}