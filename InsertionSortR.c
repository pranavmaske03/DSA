#include<stdio.h>
#include<stdlib.h>

void Insertion_Sort(int *arr,int size)
{
    if (size <= 1) 
    {
        return; 
    }

    Insertion_Sort(arr, size - 1); 

    int last = arr[size-1]; 
    int j = size - 2; 

    while (j >= 0 && arr[j] > last) 
    { 
        arr[j + 1] = arr[j]; 
        j--; 
    } 
    arr[j + 1] = last; 
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
    printf("----------------INSERTION SORT USING RECURSION-----------------------\n");
    int size = 0,targe = 0;

    printf("Enter size of the array : \n");
    scanf("%d",&size);

    int *arr = (int*)calloc(size,sizeof(int));

    Accept(arr,size);
    Display(arr,size);
    Insertion_Sort(arr,size);
    Display(arr,size);
    return 0;
}