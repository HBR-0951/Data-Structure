#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define maxSize 10
#define numSize 100

int *list, length;

void RandomList();
void InsertionSort();

int main()
{
    RandomList();
    InsertionSort();
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

void InsertionSort()
{

    int index, j, key;

    for (index = 1; index < length; index++)
    {
        key = list[index]; // 當下要比的 key ＝ list[index]
        j = index - 1;

        // 當比當下index還小的list[j]比較大石，把值往後移，直到比到key能正確擺放的位置
        while (j >= 0 && list[j] > key)
        {
            list[j + 1] = list[j];
            j--;
        }
        // 把key的直放在正確的位置
        list[j + 1] = key;
    }
}