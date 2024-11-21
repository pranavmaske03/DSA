#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void Bubble_Sort(int *arr,int size)
{
    int temp = 0,i = 0,j = 0;
    bool flag = false;

    for(i = 0; i < size-1; i++)
    {
        flag = false;
        for(j = 0; j < size-i-1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                flag = true;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(!flag) break;
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
    printf("----------------BINARY SEARCH ALGORITHAM-----------------------\n");
    int size = 0,targe = 0;

    printf("Enter size of the array : \n");
    scanf("%d",&size);

    int *arr = (int*)calloc(size,sizeof(int));

    Accept(arr,size);
    Display(arr,size);
    Bubble_Sort(arr,size);
    Display(arr,size);
    return 0;
}