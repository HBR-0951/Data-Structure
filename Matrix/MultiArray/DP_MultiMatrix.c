#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global
int ***Array;
int *order;
int count_Order = 0;
int *stack;
int count_Stack = 0;

void New_ArraySpace(int i, int a, int b);
void Minmult(int n, int d[], int P[][n]);
long Minimum(int n, int i, int j, int *k, int d[], long M[][n]);
void Order(int i, int j, int n, int P[][n]);
void Print_Array(int Signal, int n, int d[]);
void Stack(int num);
int Pop();
void Matrix_mult(int n, int a, int b, int c, int n1, int n2);

int main(void)
{
    int Signal = 0;
    scanf("%d", &Signal);
    if (Signal == 0)
    {
        int num;
        scanf("%d", &num);
        int d[num + 1];
        for (int i = 0; i <= num; i++)
        {
            scanf("%d", &d[i]);
        }
        Array = malloc(num * sizeof(int **));

        for (int i = 0; i < num; i++)
        {
            new_ArraySpace(i, d[i], d[i + 1]);
        }
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < d[i]; j++)
            {
                for (int k = 0; k < d[i + 1]; k++)
                {
                    scanf("%d", &Array[i][j][k]);
                }
            }
        }

        int P[num - 1][num];
        Minmult(num, d, P);

        order = malloc(num * 3 * sizeof(int));
        Order(0, num - 1, num, P); // 排序印出陣列順序

        stack = malloc(num * num * sizeof(int)); // 存儲乘法的排序

        Print_Array(Signal, num, d); // 用排好的順序利用stack來做矩陣乘法，並印出
    }
    else
    {
        clock_t start, end;
        start = clock();
        int num;
        scanf("%d", &num);
        int d[num + 1];
        for (int i = 0; i <= num; i++)
        {
            scanf("%d", &d[i]);
        }
        Array = malloc(num * sizeof(int **));

        for (int i = 0; i < num; i++)
        {
            new_ArraySpace(i, d[i], d[i + 1]);
        }
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < d[i]; j++)
            {
                for (int k = 0; k < d[i + 1]; k++)
                {
                    scanf("%d", &Array[i][j][k]);
                }
            }
        }

        int P[num - 1][num];
        Minmult(num, d, P);

        order = malloc(num * 3 * sizeof(int));
        Order(0, num - 1, num, P);

        stack = malloc(num * num * sizeof(int));

        Print_Array(Signal, num, d);
        end = clock();
        double diff = end - start;
        printf("%lf", diff);
    }
}

void new_ArraySpace(int i, int a, int b)
{
    Array[i] = malloc(a * sizeof(int *));
    for (int j = 0; j < a; j++)
    {
        Array[i][j] = malloc(b * sizeof(int));
    }
}

void Minmult(int n, int d[], int P[][n])
{
    long M[n][n];
    int i, j, k, diagonal;

    for (i = 0; i < n; i++)
    {
        M[i][i] = 0;
    }
    for (int diagonal = 1; diagonal <= n - 1; diagonal++)
    {
        for (int i = 0; i < n - diagonal; i++)
        {
            j = i + diagonal;

            M[i][j] = Minimum(n, i, j, &k, d, M);
            P[i][j] = k;
        }
    }
}

long Minimum(int n, int i, int j, int *k, int d[], long M[][n])
{
    int k_len = j - i;
    long min;
    int h;

    h = i;
    min = M[i][h] + M[h + 1][j] + d[i] * d[h + 1] * d[j + 1];
    *k = h;
    k_len--;

    while (k_len > 0)
    {
        h++;
        long test = M[i][h] + M[h + 1][j];
        test += (long)d[i] * (long)d[h + 1] * (long)d[j + 1];
        if (test < min)
        {
            min = test;
            *k = h;
        }
        k_len--;
    }
    return min;
}

void Order(int i, int j, int n, int P[][n])
{
    if (i == j)
    {
        order[count_Order] = i;
        count_Order++;
    }
    else
    {
        int k = P[i][j];
        order[count_Order] = -1;
        count_Order++;
        Order(i, k, n, P);
        Order(k + 1, j, n, P);
        order[count_Order] = -2;
        count_Order++;
    }
}

void Print_Array(int Signal, int n, int d[])
{
    int i = 0;
    int new_d[n * n];
    int count_array = 0;
    int count_new_d = 0;

    while (i < count_Order)
    {
        if (order[i] == -1)
        {
            i++;
        }
        else if (order[i] == -2)
        {
            int n2 = Pop();
            int n1 = Pop();

            int a, b, c;
            if (n1 >= n && n2 >= n)
            {

                int x = n1 - n;
                int y = n2 - n;
                a = new_d[2 * x];
                b = new_d[2 * x + 1];
                c = new_d[2 * y + 1];
            }
            else if (n1 >= n && n2 < n)
            {

                int x = n1 - n;
                a = new_d[2 * x];
                b = new_d[2 * x + 1];
                c = d[n2 + 1];
            }
            else if (n1 < n && n2 >= n)
            {
                // printf("step3\n");
                int y = n2 - n;
                a = d[n1];
                b = d[n1 + 1];
                c = new_d[2 * y + 1];
            }
            else
            {

                a = d[n1];
                b = d[n1 + 1];
                c = d[n2 + 1];
            }
            Array = realloc(Array, (n + count_array + 1) * sizeof(int **));

            Matrix_mult(n + count_array, a, b, c, n1, n2);

            new_d[count_new_d] = a;
            new_d[count_new_d + 1] = c;

            Stack(n + count_array);
            count_array++;
            count_new_d += 2;
            i++;
        }
        else
        {
            int num = order[i];
            Stack(num);
            i++;
        }
    }
    if (Signal == 0)
    {
        printf("%d %d \n\n", d[0], d[n]);
        for (int x = 0; x < d[0]; x++)
        {
            for (int y = 0; y < d[n]; y++)
            {
                printf("%d ", Array[n + count_array - 1][x][y]);
            }
            printf("\n");
        }
    }
}

void Stack(int num)
{
    stack[count_Stack] = num;
    count_Stack++;
}
int Pop()
{
    count_Stack--;
    int num = stack[count_Stack];
    return num;
}

void Matrix_mult(int index, int a, int b, int c, int n1, int n2)
{

    Array[index] = malloc(a * sizeof(int *));
    for (int i = 0; i < a; i++)
    {
        Array[index][i] = malloc(c * sizeof(int));
        for (int j = 0; j < c; j++)
        {
            Array[index][i][j] = 0;
        }
    }
    for (int i = 0; i < a; i++)
    {
        for (int z = 0; z < b; z++)
        {
            if (Array[n1][i][z] != 0)
            {
                for (int j = 0; j < c; j++)
                {
                    Array[index][i][j] += Array[n1][i][z] * Array[n2][z][j];
                }
            }
        }
    }
}