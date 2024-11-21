#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool Binary_Search(int *arr,int low,int high,int target)
{
    if(low > high) return false;
    if(low <= high)
    {
        int mid = low + (high - low) / 2;
       
        if(arr[mid] == target)
        {
            return true;
        }
        if(arr[mid] < target)
        {
            Binary_Search(arr,mid+1,high,target);
        }
        else
        {
            Binary_Search(arr,low,mid-1,target);
        }
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
    int size = 0,target = 0;

    printf("---------Binary Search using recursion------------------\n");
    printf("Enter size of the array : \n");
    scanf("%d",&size);

    int *arr = (int*)calloc(size,sizeof(int));

    Accept(arr,size);
    Display(arr,size);

    printf("Enter the element to search in array :\n");
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

    return 0;
}