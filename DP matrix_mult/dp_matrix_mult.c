#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0, k;
int ***array;
int * or ;
int min(int n, int i, int j, int d[], int M[][n])
{
    int num = j - 1;
    int h, q = 0;
    int str[num - i + 1], min;
    for (h = i; h <= num; h++)
    {
        if (q == 1)
        {
            min = str[0];
            (k) = h - 1;
        }
        str[q] = M[i][h] + M[h + 1][j] + d[i] * d[h + 1] * d[j + 1];
        if (str[q] < min)
        {
            min = str[q];
            (k) = h;
        }
        q++;
    }
    if (q == 1)
    {
        min = str[0];
        (k) = i;
    }
    return min;
}

void minmult(int n, int d[], int P[][n])
{
    int i, j, diagonal;
    int M[n][n];
    for (i = 0; i < n; i++)
    {
        M[i][i] = 0;
    }
    for (diagonal = 1; diagonal <= n - 1; diagonal++)
    {
        for (i = 0; i < n - diagonal; i++)
        {
            j = i + diagonal;
            M[i][j] = min(n, i, j, d, M);
            P[i][j] = k;
        }
    }
}
int **matrix_mult(int a, int b, int c, int n1, int n2)
{
    int **C = malloc(a * sizeof(int *));
    for (int i = 0; i < a; i++)
    {
        C[i] = malloc(c * sizeof(int));
        for (int j = 0; j < c; j++)
        {
            C[i][j] = 0;
        }
    }
    for (int i = 0; i < a; i++)
    {
        for (int z = 0; z < b; z++)
        {
            if (array[n1][i][z] != 0)
            {
                for (int j = 0; j < c; j++)
                {
                    C[i][j] += array[n1][i][z] * array[n2][z][j];
                }
            }
        }
    }
    return C;
}
void order(int i, int j, int n, int P[][n])
{
    if (i == j)
    {
        or [count] = i;
        count++;
    }
    else
    {
        int z = P[i][j];
        or [count] = -1;
        count++;
        order(i, z, n, P);
        order(z + 1, j, n, P);
        or [count] = -2;
        count++;
    }
}
int stack_ptr = 0;
void stack(int stack[], int num)
{
    stack[stack_ptr] = num;
    stack_ptr++;
}
int pop(int stack[])
{
    stack_ptr--;
    return stack[stack_ptr];
}
void print_index(int Num, int d[])
{
    int i = 0;

    int d_len[3 * Num];
    int d_index = 0;
    int c_array = 0;
    int c_num = 0;
    int stack_array[count];
    int **C1;
    int a, b, c;
    while (i < count)
    {
        if (or [i] == -1)
        {
        }
        else if (or [i] == -2)
        {
            printf("\nstack_first:\n");
            for (int z = 0; z < stack_ptr; z++)
            {
                printf("%d ", stack_array[z]);
            }
            printf("\n");
            int n2 = pop(stack_array);
            int n1 = pop(stack_array);
            if (n1 >= Num && n2 >= Num)
            {
                printf("1: n1>=Num && n2 >=Num \n");
                int z = n1 - Num;
                int j = n2 - Num;
                a = d_len[2 * z];
                b = d_len[2 * z + 1];
                c = d_len[2 * j + 1];

                printf("n1,n2: %d %d\n", n1, n2);
                printf("Num: %d\n", d_len[n1 - Num]);
                printf("a,b,c: %d %d %d\n", a, b, c);
            }
            else if (n1 >= Num)
            {
                printf("2: n1 >= Num\n");
                int z = n1 - Num;
                a = d_len[2 * z];
                b = d_len[n2];
                c = d[n2 + 1];
                printf("a,b,c: %d %d %d\n", a, b, c);
            }
            else if (n2 >= Num)
            {
                printf("3: n2 >= Num\n");
                int z = n2 - Num;
                a = d[n1];
                b = d[n1 + 1];
                c = d_len[2 * z + 1];
                printf("a,b,c: %d %d %d\n", a, b, c);
            }
            else
            {
                printf("4: else\n");
                a = d[n1];
                b = d[n1 + 1];
                c = d[n2 + 1];
                printf("a,b,c: %d %d %d\n", a, b, c);
            }
            // for(int z=0;z<a;z++){
            //     for(int y=0;y<b;y++){
            //         printf("%d ",array[n1][z][y]);
            //     }
            //     printf("\n");
            // }
            printf("c_array+Num:%d\n", c_array + Num);
            printf("n1,n2:%d %d\n", n1, n2);
            printf("d_index:%d\n", d_index - 1);
            printf("%d\n", 2 * (n2 - Num)); // 294
            int z = 2 * (n2 - Num);
            printf("z:%d\n", z);
            // printf("%d\n",d_len[z]);
            //  for(int z=0;z<2*(d_index-1);z++){
            //      printf("%d ",d_len[z]);
            //  }
            // printf("%d\n",d_len[2*(n1-Num)]);
            // array[c_array+Num] = matrix_mult(a,b,c,n1,n2);
            d_len[2 * d_index] = a;
            d_len[2 * d_index + 1] = c;
            printf("\nstack_mid:\n");
            for (int z = 0; z < stack_ptr; z++)
            {
                printf("%d ", stack_array[z]);
            }
            printf("\n");
            stack(stack_array, c_num + Num);
            d_index++;
            c_array++;
            c_num++;
            printf("\nstack_final:\n");
            for (int z = 0; z < stack_ptr; z++)
            {
                printf("%d ", stack_array[z]);
            }
            printf("\n");
        }
        else
        {
            int num = or [i];
            stack(stack_array, num);
        }
        i++;
    }
    // for(int z=0;z<d[0];z++){
    //     for(int y=0;y<d[Num];y++){
    //         printf("%d ",array[c_array+Num-1][z][y]);
    //     }
    //     printf("\n");
    // }
}

int main(void)
{
    int Single = 0;
    scanf("%d", &Single);
    if (Single == 0)
    {
        int Num;
        scanf("%d", &Num);
        int array_len[Num + 1];
        for (int i = 0; i < Num + 1; i++)
        {
            scanf("%d", &array_len[i]);
        }
        array = malloc(Num * 2 * sizeof(int **));

        for (int i = 0; i < Num; i++)
        {
            array[i] = malloc(array_len[i] * sizeof(int *));
            for (int j = 0; j < array_len[i]; j++)
            {
                array[i][j] = malloc(array_len[i + 1] * sizeof(int));
            }
        }
        for (int i = 0; i < Num; i++)
        {
            for (int j = 0; j < array_len[i]; j++)
            {
                for (int k = 0; k < array_len[i + 1]; k++)
                {
                    scanf("%d", &array[i][j][k]);
                }
            }
        }

        int P[Num - 1][Num];

        minmult(Num, array_len, P);

        or = malloc(Num * 3 * sizeof(int));
        order(0, Num - 1, Num, P);

        printf("%d %d \n\n", array_len[0], array_len[Num]);
        print_index(Num, array_len);
    }
    else
    {
        clock_t start, end;
        start = clock();

        int Num;
        scanf("%d", &Num);
        scanf("%d", &Num);
        int array_len[Num + 1];
        for (int i = 0; i < Num + 1; i++)
        {
            scanf("%d", &array_len[i]);
        }
        array = malloc(Num * 2 * sizeof(int **));

        for (int i = 0; i < Num; i++)
        {
            array[i] = malloc(array_len[i] * sizeof(int *));
            for (int j = 0; j < array_len[i]; j++)
            {
                array[i][j] = malloc(array_len[i + 1] * sizeof(int));
            }
        }
        for (int i = 0; i < Num; i++)
        {
            for (int j = 0; j < array_len[i]; j++)
            {
                for (int k = 0; k < array_len[i + 1]; k++)
                {
                    scanf("%d", &array[i][j][k]);
                }
            }
        }

        int P[Num - 1][Num];
        minmult(Num, array_len, P);
        or = malloc(Num * 3 * sizeof(int));
        order(0, Num - 1, Num, P);

        end = clock();
        double diff = end - start;
        printf("%lf", diff);
    }
}