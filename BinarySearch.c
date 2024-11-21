#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool Binary_Search(int *arr,int low,int high,int target)
{
    bool flag = false;
    int mid = 0;

    while(low <= high)
    {
        mid = low + (high - low) / 2;
        if(arr[mid] == target)
        {
            flag = true;
            break;
        }
        else if(arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return flag;
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
    int size = 0,target = 0;

    printf("---------Binary Search Algorigham------------------\n");
    printf("Enter number of elements : \n");
    scanf("%d",&size);

    int *arr = malloc(sizeof(int) * size);

    Accept(arr,size);
    Display(arr,size);

    printf("Enter the elements to search in array : \n");
    scanf("%d",&target);

    bool bRet = Binary_Search(arr,0,size-1,target);
    if(bRet == true)
    {
        printf("Element is found : \n");
    }
    else
    {
        printf("Element is not found : \n");
    }
}