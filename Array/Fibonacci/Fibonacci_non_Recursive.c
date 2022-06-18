#include <stdio.h>
#include<stdlib.h>

int *f;
int Fibonacci(int n);

int main()
{
    int n;
    printf("Number of Fibonacci you want: ");
    scanf("%d", &n);
    printf("Answer: %d", Fibonacci(n));
}

int Fibonacci(int n){
    f = malloc(2 * sizeof(int));
    f[0] = 0;
    f[1] = 1;
    if(n < 2){
        return f[n];
    }
    for (int i = 2; i <= n; i++){
        f = realloc(f, (i + 1) * sizeof(int));
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}