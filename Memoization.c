#include<stdio.h>

int memo[50];

int fib(int n)
{
    if(n <= 1)
    {
        return n;
    }
    else
    {
        memo[n] = fib(n-1) + fib(n-2);
        return memo[n];
    }
}

int main()
{
    printf("---------DYNAMIC PROGRAMMING--------------------\n");
    printf("------------MEMOIZATION-------------------------\n");

    printf("Result is : %d\n",fib(30));

    return 0;
}