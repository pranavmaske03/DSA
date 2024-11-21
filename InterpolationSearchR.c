#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool Interpolation_Search(int *arr,int low,int high,int target)
{
    if(low > high)
    {
        return false;
    }

    if(low <= high && target >= arr[low] && target <= arr[high])
    {
        if(arr[low] == target || arr[high] == target)
        {
            return true;
        }
        int pos = low + (((high - low) / (arr[high] - arr[low])) * (target - arr[low]));

        if(arr[pos] == target)
        {
            return true;
        }
        else if(arr[pos] < target)
        {
            Interpolation_Search(arr,pos+1,high,target);
        }
        else
        {
            Interpolation_Search(arr,low,pos-1,target);
        }
    }
    return false;
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

    printf("-------------------Interpolation Search using Recursion---------------------------\n");
    printf("Enter size of the array : \n");
    scanf("%d",&size);

    int *arr = (int*)malloc(sizeof(int) * size);

    Accept(arr,size);
    Display(arr,size);

    printf("Enter the elements to search in the array : \n");
    scanf("%d",&target);

    bool ret = Interpolation_Search(arr,0,size-1,target);
    if(ret == true)
    {
        printf("Element found \n");
    }
    else
    {
        printf("Element not found \n");
    }
    return 0;
}