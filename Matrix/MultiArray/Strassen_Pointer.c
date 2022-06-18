#include <stdio.h>
#include <time.h>
#include <stdlib.h>

_Bool N_check(int N)
{
    for (int i = 1; i <= N; i *= 2)
    {
        if (i == N)
        {
            return 1;
        }
    }
    return 0;
}

int N_change(int N)
{
    for (int i = 1;; i *= 2)
    {
        if (i > N)
        {
            return i;
        }
    }
}

int choose_max(int m1, int n1, int m2, int n2)
{
    int max = m1;
    if (n1 > max)
    {
        max = n1;
    }
    if (m2 > max)
    {
        max = m2;
    }
    if (n2 > max)
    {
        max = n2;
    }
    return max;
}
int **matrix_mult(int N, int **A, int **B)
{
    int **C = malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
    {
        C[i] = malloc(N * sizeof(int));
        for (int j = 0; j < N; j++)
        {
            C[i][j] = 0;
        }
    }
    int a11, a12, a21, a22, b11, b12, b21, b22;
    a11 = A[0][0];
    a12 = A[0][1];
    a21 = A[1][0];
    a22 = A[1][1];
    b11 = B[0][0];
    b12 = B[0][1];
    b21 = B[1][0];
    b22 = B[1][1];

    int m1, m2, m3, m4, m5, m6, m7;
    m1 = (a11 + a22) * (b11 + b22);
    m2 = (a21 + a22) * b11;
    m3 = a11 * (b12 - b22);
    m4 = a22 * (b21 - b11);
    m5 = (a11 + a12) * b22;
    m6 = (a21 - a11) * (b11 + b12);
    m7 = (a12 - a22) * (b21 + b22);

    C[0][0] = (m1 + m4 - m5 + m7);
    C[0][1] = (m3 + m5);
    C[1][0] = (m2 + m4);
    C[1][1] = (m1 + m3 - m2 + m6);

    return C;
}
int **matrix_plus(int N, int **A, int **B)
{
    int **C = malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
    {
        C[i] = malloc(N * sizeof(int));
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}
int **matrix_minus(int N, int **A, int **B)
{
    int **C = malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
    {
        C[i] = malloc(N * sizeof(int));
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}
int **strassen(int N, int **A, int **B)
{
    int **C = malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
    {
        C[i] = malloc(N * sizeof(int));
    }
    if (N <= 2)
    {
        C = matrix_mult(N, A, B);
        return C;
    }
    else
    {
        int **a11 = malloc((N / 2) * sizeof(int *));
        int **a12 = malloc((N / 2) * sizeof(int *));
        int **a21 = malloc((N / 2) * sizeof(int *));
        int **a22 = malloc((N / 2) * sizeof(int *));

        int **b11 = malloc((N / 2) * sizeof(int *));
        int **b12 = malloc((N / 2) * sizeof(int *));
        int **b21 = malloc((N / 2) * sizeof(int *));
        int **b22 = malloc((N / 2) * sizeof(int *));

        for (int i = 0; i < N / 2; i++)
        {
            a11[i] = malloc((N / 2) * sizeof(int));
            a12[i] = malloc((N / 2) * sizeof(int));
            a21[i] = malloc((N / 2) * sizeof(int));
            a22[i] = malloc((N / 2) * sizeof(int));
            b11[i] = malloc((N / 2) * sizeof(int));
            b12[i] = malloc((N / 2) * sizeof(int));
            b21[i] = malloc((N / 2) * sizeof(int));
            b22[i] = malloc((N / 2) * sizeof(int));
        }

        // 分配 a11,a12,a21,a22 ; b11,b12,b21,b22
        for (int i = 0; i < N / 2; i++)
        {
            for (int j = 0; j < N / 2; j++)
            {
                a11[i][j] = A[i][j];
                b11[i][j] = B[i][j];
            }
        }
        for (int i = 0; i < N / 2; i++)
        {
            for (int j = (N / 2), k = 0; j < N; j++, k++)
            {
                a12[i][k] = A[i][j];
                b12[i][k] = B[i][j];
            }
        }
        for (int i = (N / 2), k = 0; i < N; i++, k++)
        {
            for (int j = 0; j < N / 2; j++)
            {
                a21[k][j] = A[i][j];
                b21[k][j] = B[i][j];
            }
        }
        for (int i = (N / 2), k = 0; i < N; i++, k++)
        {
            for (int j = (N / 2), q = 0; j < N; j++, q++)
            {
                a22[k][q] = A[i][j];
                b22[k][q] = B[i][j];
            }
        }
        // m1~m7
        int **m1 = strassen(N / 2, matrix_plus(N / 2, a11, a22),
                            matrix_plus(N / 2, b11, b22));
        int **m2 = strassen(N / 2, matrix_plus(N / 2, a21, a22), b11);
        int **m3 = strassen(N / 2, a11, matrix_minus(N / 2, b12, b22));
        int **m4 = strassen(N / 2, a22, matrix_minus(N / 2, b21, b11));
        int **m5 = strassen(N / 2, matrix_plus(N / 2, a11, a12), b22);
        int **m6 = strassen(N / 2, matrix_minus(N / 2, a21, a11),
                            matrix_plus(N / 2, b11, b12));
        int **m7 = strassen(N / 2, matrix_minus(N / 2, a12, a22),
                            matrix_plus(N / 2, b21, b22));

        for (int i = 0; i < N / 2; i++)
        {
            free(a11[i]);
            free(a12[i]);
            free(a21[i]);
            free(a22[i]);
            free(b11[i]);
            free(b12[i]);
            free(b21[i]);
            free(b22[i]);
        }
        free(a11);
        free(a12);
        free(a21);
        free(a22);
        free(b11);
        free(b12);
        free(b21);
        free(b22);
        // c11,c12,c21,c22
        int **c11 = matrix_minus(N / 2, matrix_plus(N / 2, m1, m4),
                                 matrix_minus(N / 2, m5, m7));
        int **c12 = matrix_plus(N / 2, m3, m5);
        int **c21 = matrix_plus(N / 2, m2, m4);
        int **c22 = matrix_minus(N / 2, matrix_plus(N / 2, m1, m3),
                                 matrix_minus(N / 2, m2, m6));

        for (int i = 0; i < N / 2; i++)
        {
            free(m1[i]);
            free(m2[i]);
            free(m3[i]);
            free(m4[i]);
            free(m5[i]);
            free(m6[i]);
            free(m7[i]);
        }
        free(m1);
        free(m2);
        free(m3);
        free(m4);
        free(m5);
        free(m6);
        free(m7);

        for (int i = 0; i < N / 2; i++)
        {
            for (int j = 0; j < N / 2; j++)
            {
                C[i][j] = c11[i][j];
            }
        }
        for (int i = 0; i < N / 2; i++)
        {
            for (int j = N / 2, k = 0; j < N; j++, k++)
            {
                C[i][j] = c12[i][k];
            }
        }
        for (int i = (N / 2), k = 0; i < N; i++, k++)
        {
            for (int j = 0; j < N / 2; j++)
            {
                C[i][j] = c21[k][j];
            }
        }
        for (int i = (N / 2), k = 0; i < N; i++, k++)
        {
            for (int j = (N / 2), q = 0; j < N; j++, q++)
            {
                C[i][j] = c22[k][q];
            }
        }

        return C;
    }
}

int main()
{
    int Single = 0;
    scanf("%d", &Single);
    if (Single == 0)
    {
        int m1, m2, n1, n2, N;
        scanf("%d %d", &m1, &n1);
        int **a = malloc(m1 * sizeof(int *));

        for (int i = 0; i < m1; i++)
        {
            a[i] = malloc(n1 * sizeof(int));
            for (int j = 0; j < n1; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }

        scanf("%d %d", &m2, &n2);
        int **b = malloc(m2 * sizeof(int *));
        for (int i = 0; i < m2; i++)
        {
            b[i] = malloc(n2 * sizeof(int));
            for (int j = 0; j < n2; j++)
            {
                scanf("%d", &b[i][j]);
            }
        }

        N = choose_max(m1, n1, m2, n2);
        if (!(N_check(N)))
        {
            N = N_change(N);
        }
        int **A = malloc(N * sizeof(int *));
        int **B = malloc(N * sizeof(int *));
        for (int i = 0; i < N; i++)
        {
            A[i] = malloc(N * sizeof(int));
            B[i] = malloc(N * sizeof(int));
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                A[i][j] = 0;
                B[i][j] = 0;
                if (i < m1 && j < n1)
                {
                    A[i][j] = a[i][j];
                }
                if (i < m2 && j < n2)
                {
                    B[i][j] = b[i][j];
                }
            }
        }

        for (int i = 0; i < m1; i++)
        {
            free(a[i]);
        }
        for (int i = 0; i < m2; i++)
        {
            free(b[i]);
        }
        free(a);
        free(b);

        int **C;

        C = strassen(N, A, B);
        for (int i = 0; i < N; i++)
        {
            free(A[i]);
            free(B[i]);
        }
        free(A);
        free(B);

        printf("%d %d \n\n", m1, n2);
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                printf("%d ", C[i][j]);
            }
            printf("\n");
        }
        free(C);
    }
    else
    {
        clock_t start, end;
        start = clock();
        int m1, m2, n1, n2, N;
        scanf("%d %d", &m1, &n1);
        int **a = malloc(m1 * sizeof(int *));

        for (int i = 0; i < m1; i++)
        {
            a[i] = malloc(n1 * sizeof(int));
            for (int j = 0; j < n1; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }

        scanf("%d %d", &m2, &n2);
        int **b = malloc(m2 * sizeof(int *));
        for (int i = 0; i < m2; i++)
        {
            b[i] = malloc(n2 * sizeof(int));
            for (int j = 0; j < n2; j++)
            {
                scanf("%d", &b[i][j]);
            }
        }

        N = choose_max(m1, n1, m2, n2);
        if (!(N_check(N)))
        {
            N = N_change(N);
        }
        int **A = malloc(N * sizeof(int *));
        int **B = malloc(N * sizeof(int *));
        for (int i = 0; i < N; i++)
        {
            A[i] = malloc(N * sizeof(int));
            B[i] = malloc(N * sizeof(int));
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                A[i][j] = 0;
                B[i][j] = 0;
                if (i < m1 && j < n1)
                {
                    A[i][j] = a[i][j];
                }
                if (i < m2 && j < n2)
                {
                    B[i][j] = b[i][j];
                }
            }
        }

        for (int i = 0; i < m1; i++)
        {
            free(a[i]);
        }
        for (int i = 0; i < m2; i++)
        {
            free(b[i]);
        }
        free(a);
        free(b);

        int **C;

        C = strassen(N, A, B);
        for (int i = 0; i < N; i++)
        {
            free(A[i]);
            free(B[i]);
        }
        free(A);
        free(B);
        free(C);

        end = clock();
        double diff = end - start;
        printf("%lf", diff);
    }
}