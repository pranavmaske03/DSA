#include <stdio.h>
#include<limits.h>
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

int max_element(int *array, int size) 
{  
    int max = INT_MIN;  
    for(int i = 0; i < size; i++)
    {
        if(array[i] > max) 
        { 
            max = array[i];  
        }
    }
    return max;  
}
 
void Bucket_Sort(int *array, int size) 
{  
    //Finding max element of array which we will use to create buckets
    int max = max_element(array, size); 
 
    // Creating buckets 
    int bucket[max+1];  
 
    //Initializing buckets to zero
    for(int i = 0; i <= max; i++)  
    {
        bucket[i] = 0;  
    }
 
    // Pushing elements in their corresponding buckets
    for(int i = 0; i < size; i++)  
    {
        bucket[array[i]]++;
    }
 
    int j = 0;   // j is a variable which points at the index we are updating
    for (int i = 0; i <= max; i++)  
    { 
        // Running while loop until there is an element in the bucket
        while (bucket[i] > 0)  
        {  
            // Updating array and increment j          
            array[j++] = i;  
            // Decreasing count of bucket element
            bucket[i]--;   
        }  
    }  
}  
 
/* The main() begins */
int main()
{
    printf("----------------BUCKET SORT ALGORITHAM-----------------------\n");
    int size = 0,targe = 0;

    printf("Enter size of the array : \n");
    scanf("%d",&size);

    int *arr = (int*)calloc(size,sizeof(int));

    Accept(arr,size);
    Display(arr,size);
    Bucket_Sort(arr,size);
    Display(arr,size);
    return 0;
}