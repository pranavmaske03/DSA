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

void Init(int *arr,int size)
{
    for(int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
}

void Counting_Sort(int *arr,int size)
{
    int min = 0,max = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    
    if(min < 0) min = min*(-1); 

    int mapping_plus[max+1],mapping_minus[min+1];
    int output[size];
    
    Init(mapping_plus,max+1);
    Init(mapping_minus,min+1);

    for(int i = 0 ;i < size; i++)
    {
        if(arr[i] >= 0)
        {
            mapping_plus[arr[i]]++;
        }
        else if(arr[i] < 0)
        {
            mapping_minus[arr[i]* -1]++;
        }
    }
    for(int i = min-1; i >= 0; i--)
    {
        mapping_minus[i] += mapping_minus[i+1];
    }
    for(int i = 1; i <= max; i++)
    {
        mapping_plus[i] += mapping_plus[i-1];
    }
    for(int i = 0; i <= max; i++)
    {
        mapping_plus[i] = mapping_plus[i] + mapping_minus[0];
    }
    for(int i = size-1; i >= 0; i--)
    { 
        if(arr[i] >= 0)
        { 
            output[--mapping_plus[arr[i]]] = arr[i];
        }
        else if(arr[i] < 0)
        {
            output[--mapping_minus[arr[i]*-1]] = arr[i];
        }
    }
    Display(output,size+1);
} 

int main()
{
    printf("----------------COUNTING SORT TO HANDLE NEGATIVE-----------------------\n");
    int size = 0,targe = 0;

    printf("Enter size of the array : \n");
    scanf("%d",&size);

    int *arr = (int*)calloc(size,sizeof(int));

    Accept(arr,size);
    Display(arr,size);
    Counting_Sort(arr,size);
    //Display(arr,size);
    return 0;
}