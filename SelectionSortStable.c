#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void Selection_Sort(int *arr,int size)
{
    int i = 0,j = 0,min_index = 0,temp = 0,k = 0,key = 0;

    for(i = 0; i < size-1; i++)
    {
        min_index = i;
        for(j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        key = arr[min_index];

        for(k = min_index; k > i; k--)
        {
            arr[k] = arr[k-1];
        }
        arr[i] = key;
    }
}

void Accept(int *arr,int size)
{
    printf("Enter the elements of array : \n");
    for(int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
}

void Display(int *arr,int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

int main()
{
    printf("----------------SELECTION SORT STABLE-----------------------\n");
    int size = 0,targe = 0;

    printf("Enter size of the array : \n");
    scanf("%d",&size);

    int *arr = (int*)calloc(size,sizeof(int));

    Accept(arr,size);
    Display(arr,size);
    Selection_Sort(arr,size);
    Display(arr,size);
    return 0;
}