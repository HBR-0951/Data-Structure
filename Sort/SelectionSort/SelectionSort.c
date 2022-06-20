#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define maxSize 10
#define numSize 100

int *list, length;

void RandomList();
void SelectionSort();


int main()
{
    RandomList();
    SelectionSort();
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

void SelectionSort(){
    int min_id = 0;

    for (int i = 0; i < length; i++){
        min_id = i;
        for (int j = i + 1; j < length; j++){
            if(list[min_id] > list[j]){
                min_id = j;
            }
        }
        // change
        if(min_id != i){
            int temp = list[i];
            list[i] = list[min_id];
            list[min_id] = temp;
        }
    }
}