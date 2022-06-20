#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define maxSize 10
#define numSize 100

int *list, length;

void RandomList();
void GnomeSort();

int main()
{
    RandomList();
    GnomeSort();
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

void GnomeSort()
{
    int index = 0;

    while (index < length)
    {
        if (index == 0)
        {
            index++;
        }
        else if (list[index] >= list[index - 1])
        {
            index++;
        }
        // 假設當下list[index]值比較小，就跟前一個交換，並繼續往前比較，直到list[index]比前一個大
        else
        {
            int temp = list[index];
            list[index] = list[index - 1];
            list[index - 1] = temp;

            index--;
        }
    }
}