#include<stdio.h>
#include<stdlib.h>

void Insertion_Sort(int *arr,int size)
{
    int i = 0,key = 0,j = 0;
    for(i = 1; i < size; i++) 
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    printf("----------------INSERTION SORT ALGORITHM-----------------------\n");
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