#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define maxSize 10
#define numSize 100

int *list, length;

typedef struct
{
    int *S;
    int heapsize;
} Heap;

Heap H;

void RandomList();
void PutListInHeap();
void HeapSort();
void MakeHeap();
void SiftDown(int i);
void RemoveKey();
int Root();

int main()
{
    RandomList();
    PutListInHeap();
    HeapSort();
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

void PutListInHeap()
{
    H.S = malloc((length + 1) * sizeof(int));
    for (int i = 0; i < length; i++)
    {
        H.S[i + 1] = list[i];
    }
}

void HeapSort()
{
    MakeHeap();
    RemoveKey();
}

void MakeHeap()
{
    H.heapsize = length;

    for (int i = length / 2; i >= 1; i--)
    { // 從最大index的根節點找起（index要從1開始，方便計算
      // ex: 根節點index為4時，其左右子節點index為 4*2 和 (4*2)+1）
        SiftDown(i);
    }
}

void SiftDown(int i)
{
    int parent, largerchild; // largerchild: 找到左右子節點最大者，和根節點比大小
    int siftkey;             // 要拿來比較的根節點的值，假如比較小繼續往下比
    int spotfound = 0;       // bool

    siftkey = H.S[i];

    parent = i;

    // while(當節點index沒有超過總長度時，或者是沒有找到適合根節點放置的位置時)
    while (2 * parent <= H.heapsize && !spotfound)
    {
        // 找到最大的 child
        if (2 * parent < H.heapsize && H.S[2 * parent] < H.S[2 * parent + 1])
        {
            largerchild = 2 * parent + 1;
        }
        else
        {
            largerchild = 2 * parent;
        }

        // 和根節點比較，假如根節點比較小，就交換
        if (siftkey < H.S[largerchild])
        {
            H.S[parent] = H.S[largerchild];
            parent = largerchild;
        }
        else
        {
            spotfound = 1;
        }
        H.S[parent] = siftkey;
    }
}

void RemoveKey()
{ // 回傳根節點(最大值)，並重新用SiftDown排序Heap
    for (int i = length - 1; i >= 0; i--)
    {
        list[i] = Root();
    }
}

int Root()
{
    int keyout = H.S[1];      //回傳根節點
    H.S[1] = H.S[H.heapsize]; // 把最後面節點的值給根節點
    H.heapsize -= 1;          // 將 Heap 總數減一，就像刪除最後面的節點
    SiftDown(1);              // 重新排序Heap
    return keyout;
}