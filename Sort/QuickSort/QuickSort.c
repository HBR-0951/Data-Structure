#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define maxSize 10
#define numSize 100

int *list, length;

void RandomList();
void QuickSort(int low, int hight);
void Partition(int low, int hight, int *pivotpoint);

int main()
{
    RandomList();
    QuickSort(0, length);

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

void QuickSort(int low, int hight)
{
    if (hight <= low)
    {
        return;
    }
    int pivotpoint;

    Partition(low, hight, &pivotpoint);
    QuickSort(low, pivotpoint);
    QuickSort(pivotpoint + 1, hight);
}

void Partition(int low, int hight, int *pivotpoint)
{
    int pivotitem, i, j;
    j = low;
    pivotitem = list[low];

    for (i = low + 1; i < hight; i++)
    {
        if (list[i] < pivotitem)
        {
            j++;
            // switch list[i], list[j]
            int temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        }
    }
    *pivotpoint = j;
    // switch list[low], list[pivotpoint]
    int temp = list[low];
    list[low] = list[*pivotpoint];
    list[*pivotpoint] = temp;
}