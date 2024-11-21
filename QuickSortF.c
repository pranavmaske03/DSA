#include <stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) 
{
    int pivot = arr[low];
    int k = high;

    for (int i = high; i > low; i--) 
    {
        if (arr[i] > pivot)
        {
            swap(&arr[i], &arr[k--]);
        }
    }
    swap(&arr[low], &arr[k]);

    return k; 
}

void Quick_Sort(int *arr, int low, int high) 
{
    if (low < high) 
    {
        int idx = partition(arr, low, high);

        Quick_Sort(arr, low, idx - 1);
        Quick_Sort(arr, idx + 1, high);
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
    printf("----------------QUICKSORT ALGORITHAM-----------------------\n");
    int size = 0,targe = 0;

    printf("Enter size of the array : \n");
    scanf("%d",&size);

    int *arr = (int*)calloc(size,sizeof(int));

    Accept(arr,size);
    Display(arr,size);
    Quick_Sort(arr,0,size-1);
    Display(arr,size);
    return 0;
}