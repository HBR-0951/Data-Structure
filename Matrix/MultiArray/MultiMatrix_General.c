#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define array_SIZE 10
#define num_SIZE 10

int **array_A, **array_B, **array_C;
int size_a1, size_a2, size_b1, size_b2;

void RandomTwoArray();
void MultiArray();

int main()
{
    RandomTwoArray(); // get two array: array_A, array_B
    MultiArray();     // return array_C for (array_A * array_B)

    printf("\nAfter Multi (%d * %d)\n", size_a1, size_b2);
    for (int i = 0; i < size_a1; i++)
    {
        for (int j = 0; j < size_b2; j++)
        {
            printf("%d ", array_C[i][j]);
        }
        printf("\n");
    }
}

void RandomTwoArray()
{
    srand(time(NULL));

    size_a1 = (rand() % array_SIZE) + 1;
    size_b2 = (rand() % array_SIZE) + 1;
    size_a2 = (rand() % array_SIZE) + 1;
    size_b1 = size_a2;

    array_A = malloc(size_a1 * sizeof(int *));
    array_B = malloc(size_b1 * sizeof(int *));

    for (int i = 0; i < size_a1; i++)
    {
        array_A[i] = malloc(size_a2 * sizeof(int));
        for (int j = 0; j < size_a2; j++)
        {
            array_A[i][j] = (rand() % num_SIZE) + 1;
        }
    }

    for (int i = 0; i < size_b1; i++)
    {
        array_B[i] = malloc(size_b2 * sizeof(int));
        for (int j = 0; j < size_b2; j++)
        {
            array_B[i][j] = (rand() % num_SIZE) + 1;
        }
    }

    // print array_A, array_B
    printf("Before Multi:\n\nArray_A (%d * %d):\n", size_a1, size_a2);
    for (int i = 0; i < size_a1; i++)
    {
        for (int j = 0; j < size_a2; j++)
        {
            printf("%d ", array_A[i][j]);
        }
        printf("\n");
    }
    printf("\nArray_B(%d * %d):\n", size_b1, size_b2);
    for (int i = 0; i < size_b1; i++)
    {
        for (int j = 0; j < size_b2; j++)
        {
            printf("%d ", array_B[i][j]);
        }
        printf("\n");
    }
}

void MultiArray()
{

    array_C = malloc(size_a1 * sizeof(int *));

    for (int i = 0; i < size_a1; i++)
    {
        array_C[i] = malloc(size_b2 * sizeof(int));
        for (int j = 0; j < size_b2; j++)
        {
            array_C[i][j] = 0;
        }
    }
    for (int i = 0; i < size_a1; i++)
    {
        for (int k = 0; k < size_a2; k++)
        {
            if (array_A[i][k] != 0)
            {
                for (int j = 0; j < size_b2; j++)
                {
                    array_C[i][j] += array_A[i][k] * array_B[k][j];
                }
            }
        }
    }
}