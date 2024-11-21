#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr,int low,int high)
{
    int pivot = arr[high];

    int i = (low - 1);

    for(int j = low;j <= high - 1;j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i + 1],&arr[high]);
    return (i + 1);
}

void Quick_Sort(int *arr,int low,int high)
{
    int stack[high-low+1];
    int top = -1;

    stack[++top] = low;
    stack[++top] = high;

    while(top >= 0)
    {
        high = stack[top--];
        low = stack[top--];

        int pivot = partition(arr,low,high);

        if(pivot - 1 > low)
        {
            stack[++top] = low;
            stack[++top] = pivot - 1;
        }

        if(pivot + 1 < high)
        {
            stack[++top] = pivot + 1;
            stack[++top] = high;
        }
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