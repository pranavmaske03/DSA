#include<stdio.h>
#include<stdlib.h>

int minIndex(int *arr, int i, int j)
{
    if(i == j)
    {
        return i; 
    }
    int k = minIndex(arr, i + 1, j);
    return (arr[i] < arr[k])? i : k;
}

void Display(int *arr,int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void Selection_Sort(int *arr, int size, int index)
{
    if(index == size)
       return;
    
    int k = minIndex(arr, index, size-1);
    printf("k = %d\n",k);  

    if(k != index)
    {
        int temp = arr[k];
        arr[k] = arr[index];
        arr[index] = temp;
    }
    Selection_Sort(arr,size,index + 1);
}

void Accept(int *arr,int size)
{
    printf("Enter the elements of array : \n");
    for(int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
}

int main()
{
    printf("----------------SELECTION SORT RECURSIVE-----------------------\n");
    int size = 0,targe = 0;

    printf("Enter size of the array : \n");
    scanf("%d",&size);

    int *arr = (int*)calloc(size,sizeof(int));

    Accept(arr,size);
    Display(arr,size);
    Selection_Sort(arr,size,0);
    Display(arr,size);
    return 0;
}