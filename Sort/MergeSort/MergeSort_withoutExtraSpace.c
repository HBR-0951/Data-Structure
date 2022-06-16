#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define maxSize 10
#define numSize 100

int *list, length;

void RandomList();
void MergeSort(int n, int h, int m, int start); // start 記錄起始位置
void Merge(int n, int h, int m, int start);

int main()
{
    RandomList();
    MergeSort(length,length/2, length - (length/2), 0);
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

void MergeSort(int n, int h, int m, int start)
{
    if(n > 1){
        MergeSort(h, h / 2, h - (h / 2), start); 
        MergeSort(m, m / 2, m - (m / 2), start + h);

        Merge(n, h, m, start);
    }
}

void Merge(int n, int h, int m, int start){

    int i = start;
    int j = (start + h);
    int S[n], k = 0; // 儲存合併後的陣列，無法避免
    
    while(i < (start + h) && j < (start + n)){
        
        if (list[i] < list[j])
        {
            S[k] = list[i];
            i++;
        }
        else{
            S[k] = list[j];
            j++;
        }
        k++;
    }
    if (i < (start + h)){
        do{
            S[k] = list[i];
            i++;
            k++;
        } while (i < (start + h));
    }
    else{
        do
        {
            S[k] = list[j];
            j++;
            k++;
        } while (j < (start + n));
    }

    i = start;
    for (int p = 0; p < n; p++)
    {
        list[i] = S[p];
        i++;
    }

}