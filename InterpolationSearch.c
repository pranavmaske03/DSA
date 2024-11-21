#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool Interpolation_Search(int *arr,int size,int target)
{
    int low = 0,high = (size - 1),pos = 0;
    bool flag = false;

    while(low <= high && target >= arr[low] && target <= arr[high])
    {
        if(low == high)
        {
            if(arr[low] == target)
            {
                flag = true;
                break;
            }
            else
            {
                break;
            }
        }
        pos = low + (((high - low) / (arr[high] - arr[low])) * (target - arr[low]));

        if(arr[pos] == target)
        {
            flag = true;
            break;
        }
        else if(arr[pos] < target)
        {
            low = pos + 1;
        }
        else
        {
            high = pos - 1;
        }
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

    printf("-------------------Interpolation Search Algorithm---------------------------\n");
    printf("Enter size of the array : \n");
    scanf("%d",&size);

    int *arr = (int*)malloc(sizeof(int) * size);

    Accept(arr,size);
    Display(arr,size);

    printf("Enter the elements to search in the array : \n");
    scanf("%d",&target);

    bool ret = Interpolation_Search(arr,size,target);
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