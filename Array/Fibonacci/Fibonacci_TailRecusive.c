#include <stdio.h>

int Fibonacci(int n, int first, int second);

int main()
{
    int n;

    printf("Number of Fibonacci you want: ");
    scanf("%d", &n);
    printf("Answer: %d", Fibonacci(n,0,1));
}

int Fibonacci(int n, int first, int second)
{
    if (n == 0){
        return first;
    }
    else if(n == 1){
        return second;
    }
    else
    {
        return Fibonacci(n-1, second, first + second);
    }
}