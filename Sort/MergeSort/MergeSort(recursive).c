#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define maxSize 10
#define numSize 100

int *list, length;

void RandomList();
void MergeSort();

int main()
{
    RandomList();
    MergeSort();
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

}

void MergeSort(){

}