#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define maxSize 10
#define numSize 100

int *list, length;

void RandomList();
void ShellSort(); // improve InsertionSort

int main()
{
    RandomList();
    ShellSort();
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

void ShellSort(){
    int gap = length / 2;

    while(gap > 0){

        for (int i = 0; i< length; i += gap){
            int temp = list[i];
            int j = i;

            while(j >= gap && list[j - gap] > temp){
                list[j] = list[j - gap];
                j -= gap;
            }
            list[j] = temp;
        }
            gap /= 2;
    }
}