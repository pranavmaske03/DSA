#include<stdio.h>
#include<stdlib.h>

void Counting_Sort(int *arr, int size) 
{
    int output[size];
    int i = 0,index = 0;
    int max = arr[0];

    for(i = 1; i < size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
  
    int count[max + 1];

    for(i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    for(i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }

/*
    for(i = 0; i <= max; i++) 
    {
        while(count[i] > 0)
        {
            arr[index++] = i;
            count[i]--;
        }
    }
*/
    for(i = 1; i <= max; i++)
    {
        count[i] += count[i-1];
    }
   
    for(i = size-1; i >= 0; i--)
    {
        output[--count[arr[i]]] = arr[i];
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
    printf("----------------COUNTING SORT ALGORITHAM-----------------------\n");
    int size = 0,targe = 0;

    printf("Enter size of the array : \n");
    scanf("%d",&size);

    int *arr = (int*)calloc(size,sizeof(int));

    Accept(arr,size);
    Display(arr,size);
    Counting_Sort(arr,size);
    Display(arr,size);
    return 0;
}