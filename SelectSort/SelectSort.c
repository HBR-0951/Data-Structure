#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define maxSize 10
#define numSize 100

int *list, length;

void RandomList();
void SelectSort();

int main()
{
    RandomList();
    SelectSort();
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
}
void SelectSort()
{

    printf("Before sort:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", list[i]);
    }

    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (list[i] > list[j])
            {
                int temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }

    printf("\nAfter sort:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", list[i]);
    }
}
