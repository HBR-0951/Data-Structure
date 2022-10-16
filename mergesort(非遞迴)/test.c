
#include <stdio.h>
#include <string.h>

int t[10], flag = 0;

void Merge(int a[], int b[], int l, int m, int r)
{
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r)
    {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= m)
        b[k++] = a[i++];
    while (j <= r)
        b[k++] = a[j++];
}

void getPos(int a[], int t[], int n)
{
    t[flag++] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] < a[i])
            t[flag++] = i + 1;
    }
    for (int i = 0; i < flag; i++)
        printf("%d  ", t[i]);
    printf("\n");
}
void MergePass(int x[], int y[], int s, int n)
{
    int i = 0; // i表示第幾段
    while (i <= flag - 2 * s)
    {
        int r = ((i + 2 * s) < flag) ? t[i + 2 * s] : n;
        Merge(x, y, t[i], t[i + s] - 1, r - 1); //把兩個長度為s的段合併在一起
        i = i + 2 * s;
    }
    if (i + s < flag)
        Merge(x, y, t[i], t[i + s] - 1, n - 1);
    else
    {
        for (int j = t[i]; j <= n - 1; j++)
        {
            y[j] = x[j];
        }
    }
}
void MergeSort(int a[], int n)
{
    int b[10];
    int s = 1;
    while (s < flag)
    {                          //最多flag段
        MergePass(a, b, s, n); //把a合併到b中
        s += s;
        MergePass(b, a, s, n); //把b合併到a中
        s += s;
    }
}
int main()
{
    int a[10] = {2, 1, 5, 3, 4, 9, 7, 8, 0, 6};
    int n = 10;
    getPos(a, t, n);
    MergeSort(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}