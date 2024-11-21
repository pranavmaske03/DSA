#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int min(int a,int b) { return (a <= b) ? a : b; }

bool Fibonacci_Search(int *arr,int size,int target)
{
    int fib_num2 = 0; 
    int fib_num1 = 1; 
    int fib = fib_num2 + fib_num1; 
    bool flag = false;  
    
    while (fib < size) 
    { 
        fib_num2 = fib_num1; 
        fib_num1 = fib; 
        fib = fib_num2 + fib_num1; 
    } 
    
    int offset = -1; 
  
    while (fib > 1) 
    { 
        int i = min(offset + fib_num2, size - 1); 
  
        if (arr[i] < target) 
        { 
            fib = fib_num1; 
            fib_num1 = fib_num2; 
            fib_num2 = fib - fib_num1; 
            offset = i; 
        } 
        else if (arr[i] > target) 
        { 
            fib = fib_num2; 
            fib_num1 = fib_num1 - fib_num2; 
            fib_num2 = fib - fib_num1; 
        } 
        else
        {
            flag = true;
            break;
        }
    } 
  
    if(fib_num1 && arr[offset + 1] == target) 
    {
        flag = true;
    }

    return flag; 
}

void Accept(int *arr,int size)
{
    printf("Enter the elements of the array :\n");
    for(int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
}

void Display(int *arr,int size)
{
    printf("Elements of the array are : \n");
    for(int i = 0; i < size; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

int main()
{
    int size = 0,target = 0;

    printf("-------------------Fibonacci Search Algorithm---------------------------\n");
    printf("Enter size of the array : \n");
    scanf("%d",&size);

    int *arr = (int*)malloc(sizeof(int) * size);

    Accept(arr,size);
    Display(arr,size);

    printf("Enter the elements to search in the array : \n");
    scanf("%d",&target);

    bool bRet = Fibonacci_Search(arr,size,target);
    if(bRet == true)
    {
        printf("Element found \n");
    }
    else
    {
        printf("Element not found \n");
    }
    return 0;
}