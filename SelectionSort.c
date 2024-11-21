#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void Selection_Sort(int *arr,int size)
{
    int temp = 0,i = 0,j = 0,min_index = 0;

    for(i = 0; i < size-1; i++)
    {
        min_index = i;
        for(j = i+1; j < size; j++)
        {
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
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
    printf("----------------SELECTION SORT ALGORITHAM-----------------------\n");
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