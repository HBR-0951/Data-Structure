#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define maxSize 10
#define numSize 100

int *list, length, Find;

void RandomSortedList();
void QuickSort(int low, int hight);
void Partition(int low, int hight, int *pivotpoint);
int BinarySearch(int low, int hight);

int main()
{
    RandomSortedList();
    int answer = BinarySearch(0, length);
    printf("%d is in the list[%d]", Find, answer);
}
void RandomSortedList()
{

    srand(time(NULL));
    length = (rand() % maxSize) + 1;

    printf("Size: %d\n", length);

    list = malloc(length * sizeof(int));

    for (int i = 0; i < length; i++)
    {
        list[i] = (rand() % numSize) + 1;
    }

    Find = list[rand() % length];

    QuickSort(0, length);

    printf("SortedList:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
    printf("find %d\n", Find);
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

int BinarySearch(int low, int hight)
{
    if (low > hight)
    {
        return 0;
    }
    else
    {
        int mid = ((low + hight) / 2);

        if (Find == list[mid])
        {
            return mid;
        }
        else if (Find > list[mid])
        {
            return BinarySearch(mid + 1, hight);
        }
        else
        {
            return BinarySearch(low, mid);
        }
    }
}