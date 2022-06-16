#include <stdio.h>

// A[0~mid],A[(mid+1)~end]為以排序，把兩個已排序的陣列比對後放入B[0~end]裡，而
// Ｂ為已排序陣列，最後再把Ｂ複製的Ａ上。
void merge(int A[], int B[], int start, int mid, int end)
{
    int i = start, j = mid + 1, k = 0;
    while (i <= mid && j <= end)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for (i = 0; i < k; i++)
    {
        A[start + i] = B[i];
    }
}
//每次切成length長的片段，然後兩兩作 merge 排序
void mergePass(int A[], int B[], int length, int n)
{
    int i = 0;
    for (i = 0; (i + (2 * length)) - 1 < n; i += 2 * length)
    {
        merge(A, B, i, i + length - 1, i + 2 * length - 1);
    }
    if ((i + length - 1) < n)
    { //當片段僅為一個length的長度使得無法倆倆比較時，自己排序
        merge(A, B, i, i + length - 1, n - 1);
    }
}
void mergesort(int S[], int n)
{
    int length;
    int B[n];
    // 切成length長的片段作merge，length = 2^k
    for (length = 1; length < n; length *= 2)
    {
        mergePass(S, B, length, n);
    }
}
int main()
{
    int S[10] = {4, 3, 1, 6, 4, 7, 3, 8, 9};
    int n = 9;
    mergesort(S, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", S[i]);
    }
}