#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

bool Linear_Search(int *arr,int size,int target)
{
    int iCnt = 0;
    for(iCnt = 0; iCnt < size; iCnt++)
    {
        if(arr[iCnt] == target)
        {
            break;
        }
    }
    if(iCnt == size)
    {
        return false;
    }
    else
    {
        return true;
    }
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
    printf("------------------Linear Search using---------------------\n");

    int size = 0,search = 0;
    int *arr = NULL;

    printf("Enter number of elements in the array : \n");
    scanf("%d",&size);

    arr = (int*)malloc(sizeof(int)*size);

    Accept(arr,size);
    Display(arr,size);

    printf("Enter the element you want to search : \n");
    scanf("%d",&search);

    Linear_Search(arr,size,search);   

    printf("-------------------------------------------------------------------\n");


    return 0;
}