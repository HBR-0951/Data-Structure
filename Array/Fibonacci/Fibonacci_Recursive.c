#include<stdio.h>

int Fibonacci(int n);


int main(){
    int n;

    printf("Number of Fibonacci you want: ");
    scanf("%d", &n);
    printf("Answer: %d",Fibonacci(n));
}

int Fibonacci(int n){
    if(n < 2){
        return n;
    }
    else{
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}