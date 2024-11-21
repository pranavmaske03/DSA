#include<stdio.h>
#include<stdlib.h>

void Linear_Search(int *arr,int size,int search)
{
    if(size == -1)
    {
        printf("Element not found\n");
        return;
    }
    if(arr[size] == search)
    {
        printf("Element found at index number : %d\n",size);
        return;
    }

    Linear_Search(arr,size-1,search);
}

void Linear_Search1(int *arr,int size,int search)
{
    static int i = 0;
    if(i >= size)
    {
        printf("Element not found\n");
        return;
    }
    if(arr[i] == search)
    {
        printf("Element found at index number : %d\n",i);
        return;
    }
    i++;
    Linear_Search1(arr,size,search);
}

void Accept(int *arr,int size)
{
    int i = 0;
    printf("Enter the elements of array : \n");
    for(i = 0;i < size;i++)
    {
        scanf("%d",&arr[i]);
    }
}

void Display(int *arr,int size)
{
    int i = 0;
    printf("Elements of array are : \n");
    for(i = 0;i < size;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

int main()
{
    printf("------------------Linear Search using recursion--------------------\n");

    int size = 0,search = 0;
    int *arr = NULL;

    printf("Enter number of elements in the array : \n");
    scanf("%d",&size);

    arr = (int*)malloc(sizeof(int)*size);

    Accept(arr,size);
    Display(arr,size);

    printf("Enter the element you want to search : \n");
    scanf("%d",&search);

    //Linear_Search(arr,size-1,search);   
    Linear_Search1(arr,size,search); 

    printf("-------------------------------------------------------------------\n");


    return 0;
}