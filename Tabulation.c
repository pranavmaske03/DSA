#include<stdio.h>

int fib(int n)
{
    if(n <= 1)
    {
        return n;
    }
    else 
    {
        int table[n+1];
        table[0] = 0;
        table[1] = 1;
        for (int i = 2; i <= n; i++) 
        {
            table[i] = table[i - 1] + table[i - 2];
        }
        return table[n];
    }
}

int main()
{
    printf("---------DYNAMIC PROGRAMMING--------------------\n");
    printf("------------TABULATION-------------------------\n");

    printf("Result is : %d\n",fib(30));

    return 0;
}