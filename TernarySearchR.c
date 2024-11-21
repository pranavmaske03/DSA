#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool Ternary_Search(int *arr,int low,int high,int target)
{
    if(low > high) return false;
    if(low <= high)
    {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        if(arr[mid1] == target)
        {
            return true;
        }
        if(arr[mid2] == target)
        {
            return true;
        }

        if(arr[mid1] < target)
        {
            Ternary_Search(arr,mid1+1,high,target);
        }
        else if(arr[mid2] > target)
        {
            Ternary_Search(arr,low,mid2-1,target);
        }
        else
        {
            Ternary_Search(arr,mid1+1,mid2-1,target);
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

    printf("---------Ternary Search Algorigham------------------\n");
    printf("Enter number of elements : \n");
    scanf("%d",&size);

    int *arr = malloc(sizeof(int) * size);

    Accept(arr,size);
    Display(arr,size);

    printf("Enter the elements to search in array : \n");
    scanf("%d",&target);

    bool bRet = Ternary_Search(arr,0,size-1,target);
    if(bRet == true)
    {
        printf("Element is found : \n");
    }
    else
    {
        printf("Element is not found : \n");
    }
}