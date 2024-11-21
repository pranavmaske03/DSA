#include<stdio.h>
#include<stdlib.h>

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

int getMax(int *arr, int n)
{
    int max = arr[0];
    for(int i = 1; i < n; i++)
    {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

void Counting_Sort(int *arr,int size,int exp)
{
    int output[size];
    int i,count[10] = {0};
 
    for (i = 0; i < size; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }
    for (i = 1; i < 10; i++)
    {
        count[i] += count[i-1];
    }
    for (i = size - 1; i >= 0; i--) 
    {
        output[--count[(arr[i] / exp) % 10]] = arr[i];
    }
    for (i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}

void Radix_Sort(int *arr,int size)
{
    int m = getMax(arr, size);
   
    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        Counting_Sort(arr, size, exp);
    }
}

int main()
{
    printf("----------------RADIX SORT ALGORITHAM-----------------------\n");
    int size = 0,targe = 0;

    printf("Enter size of the array : \n");
    scanf("%d",&size);

    int *arr = (int*)calloc(size,sizeof(int));

    Accept(arr,size);
    Display(arr,size);
    Radix_Sort(arr,size);
    Display(arr,size);
    return 0;
}