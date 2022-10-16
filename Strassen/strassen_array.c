#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Threshold 16

void matrix_mult(int n, int A[n][n], int B[n][n], int C[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            if (A[i][k] != 0)
            {
                for (int j = 0; j < n; j++)
                {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }
}

void matrix_plus(int n, int A[n][n], int B[n][n], int C[n][n])
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void matrix_minus(int n, int A[n][n], int B[n][n], int C[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassen(int n, int A[n][n], int B[n][n], int C[n][n])
{

    if (n <= Threshold)
    {

        matrix_mult(n, A, B, C);
    }
    else
    {
        int k = n / 2;
        int A11[n / 2][n / 2], A12[n / 2][n / 2], A21[n / 2][n / 2], A22[n / 2][n / 2];
        int B11[n / 2][n / 2], B12[n / 2][n / 2], B21[n / 2][n / 2], B22[n / 2][n / 2];
        int M1[n / 2][n / 2], M2[n / 2][n / 2], M3[n / 2][n / 2], M4[n / 2][n / 2],
            M5[n / 2][n / 2], M6[n / 2][n / 2], M7[n / 2][n / 2];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i < (n / 2) && j < (n / 2))
                {
                    A11[i][j] = A[i][j];
                    B11[i][j] = B[i][j];
                }
                else if (i < (n / 2) && j >= (n / 2))
                {
                    A12[i][j - (n / 2)] = A[i][j];
                    B12[i][j - (n / 2)] = B[i][j];
                }
                else if (i >= (n / 2) && j < (n / 2))
                {
                    A21[i - (n / 2)][j] = A[i][j];
                    B21[i - (n / 2)][j] = B[i][j];
                }
                else if (i >= (n / 2) && j >= (n / 2))
                {
                    A22[i - (n / 2)][j - (n / 2)] = A[i][j];
                    B22[i - (n / 2)][j - (n / 2)] = B[i][j];
                }
            }
        }

        int a[n / 2][n / 2], b[n / 2][n / 2];

        matrix_plus(n / 2, A11, A22, a);
        matrix_plus(n / 2, B11, B22, b);

        strassen(k, a, b, M1);

        // m2
        matrix_plus(n / 2, A21, A22, a);

        strassen(k, a, B11, M2);

        // m3
        matrix_minus(n / 2, B12, B22, b);

        strassen(k, A11, b, M3);

        // m4
        matrix_minus(n / 2, B21, B11, b);

        strassen(k, A22, b, M4);
        // m5
        matrix_plus(n / 2, A11, A12, a);

        strassen(k, a, B22, M5);

        // m6
        matrix_minus(n / 2, A21, A11, a);
        matrix_plus(n / 2, B11, B12, b);

        strassen(k, a, b, M6);

        // m7
        matrix_minus(n / 2, A12, A22, a);
        matrix_plus(n / 2, B21, B22, b);

        strassen(k, a, b, M7);

        int C11[n / 2][n / 2], C12[n / 2][n / 2], C21[n / 2][n / 2], C22[n / 2][n / 2];
        // c11
        matrix_plus(n / 2, M1, M4, a);

        matrix_minus(n / 2, a, M5, b);

        matrix_plus(n / 2, b, M7, C11);

        // c12
        matrix_plus(n / 2, M3, M5, C12);

        // c21
        matrix_plus(n / 2, M2, M4, C21);

        // c22
        matrix_plus(n / 2, M1, M3, a);

        matrix_minus(n / 2, a, M2, b);

        matrix_plus(n / 2, b, M6, C22);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i < (n / 2) && j < (n / 2))
                {
                    C[i][j] = C11[i][j];
                }
                else if (i < (n / 2) && j >= (n / 2))
                {
                    C[i][j] = C12[i][j - (n / 2)];
                }
                else if (i >= (n / 2) && j < (n / 2))
                {
                    C[i][j] = C21[i - (n / 2)][j];
                }
                else if (i >= (n / 2) && j >= (n / 2))
                {
                    C[i][j] = C22[i - (n / 2)][j - (n / 2)];
                }
            }
        }
    }
}
_Bool matrix_check(int n)
{
    for (int i = 1; i <= n; i *= 2)
    {
        if (i == n)
        {
            return 1;
        }
    }
    return 0;
}

int change_index(int n)
{
    int i = 1;
    while (i < n)
    {
        i *= 2;
    }
    return i;
}
int choose_max(int m1, int m2, int n1, int n2)
{
    int max = m1;
    if (m2 > max)
    {
        max = m2;
    }
    if (n1 > max)
    {
        max = n1;
    }
    if (n2 > max)
    {
        max = n2;
    }
    return max;
}
int main()
{

    int m1, n1, m2, n2, n, Single = 0;

    scanf("%d\n", &Single);
    if (Single == 0)
    {
        scanf("%d %d", &m1, &n1);
        int a[m1][n1];
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < n1; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }

        scanf("%d %d", &m2, &n2);
        int b[m2][n2];
        for (int i = 0; i < m2; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                scanf("%d", &b[i][j]);
            }
        }
        n = choose_max(m1, m2, n1, n2);
        if (!matrix_check(n))
        {
            n = change_index(n); // change to 2^k
        }
        int A[n][n], B[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i < m1 && j < n1)
                {
                    A[i][j] = a[i][j];
                }
                else
                {
                    A[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i < m2 && j < n2)
                {
                    B[i][j] = b[i][j];
                }
                else
                {
                    B[i][j] = 0;
                }
            }
        }
        int C[n][n];
        strassen(n, A, B, C);

        printf("%d %d \n\n", m1, n2);
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                printf("%d ", C[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        clock_t start, end;
        start = clock();
        scanf("%d %d", &m1, &n1);
        int a[m1][n1];
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < n1; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }

        scanf("%d %d", &m2, &n2);
        int b[m2][n2];
        for (int i = 0; i < m2; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                scanf("%d", &b[i][j]);
            }
        }
        n = choose_max(m1, m2, n1, n2);
        if (!matrix_check(n))
        {
            n = change_index(n); // change to 2^k
        }
        int A[n][n], B[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i < m1 && j < n1)
                {
                    A[i][j] = a[i][j];
                }
                else
                {
                    A[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i < m2 && j < n2)
                {
                    B[i][j] = b[i][j];
                }
                else
                {
                    B[i][j] = 0;
                }
            }
        }
        int C[n][n];
        strassen(n, A, B, C);

        end = clock();
        double diff = end - start;
        printf("%lf", diff);
    }
}