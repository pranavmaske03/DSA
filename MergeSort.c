#include<stdio.h>
#include<stdlib.h>

void merge(int *arr, int left, int mid, int right)
{
    int i = 0,j = 0, k = 0;
    int size1 = mid - left + 1;
    int size2 = right - mid;

    int l_arr[size1], r_arr[size2];

    printf("%d\t%d\t%d\t%d\t%d\n",size1,size2,left,right,mid);
    for (i = 0; i < size1; i++)
    {
        l_arr[i] = arr[left + i];
    }
    for (j = 0; j < size2; j++)
    {
        r_arr[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;
    while (i < size1 && j < size2) 
    {
        if (l_arr[i] <= r_arr[j]) 
        {
            arr[k] = l_arr[i];
            i++;
        }
        else 
        {
            arr[k] = r_arr[j];
            j++;
        }
        k++;
    }
    while(i < size1) 
    {
        arr[k] = l_arr[i];
        i++;
        k++;
    }
    while(j < size2) 
    {
        arr[k] = r_arr[j];
        j++;
        k++;
    }
}

void Merge_Sort(int *arr, int left, int right)
{
    if (left < right)  
    {
        int mid = left + (right - left) / 2;

        Merge_Sort(arr,left,mid);
        Merge_Sort(arr,mid + 1,right);

        merge(arr,left,mid,right);
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
    printf("----------------MERGE SORT ALGORITHAM-----------------------\n");
    int size = 0,targe = 0;

    printf("Enter size of the array : \n");
    scanf("%d",&size);

    int *arr = (int*)calloc(size,sizeof(int));

    Accept(arr,size);
    Display(arr,size);
    Merge_Sort(arr,0,size-1);
    Display(arr,size);
    return 0;
}   