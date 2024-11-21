#include <stdio.h> 
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

void buildMaxHeap(int *arr, int n) 
{ 
	for(int i = 1; i < n; i++) 
	{ 
		if(arr[i] > arr[(i - 1) / 2]) 
		{ 
			int j = i; 
	
			while(arr[j] > arr[(j - 1) / 2]) 
			{ 
				int temp = arr[j]; 
				arr[j] = arr[(j-1)/2]; 
				arr[(j-1)/2] = temp; 
				j = (j - 1) / 2; 
			} 
		} 
	} 
    Display(arr,n);
} 

void Heap_Sort(int *arr, int n) 
{ 
	buildMaxHeap(arr, n); 

    int j = 0, index = 0; 	
	for (int i = n - 1; i > 0; i--) 
	{ 
		int temp = arr[0]; 
		arr[0] = arr[i]; 
		arr[i] = temp; 
	
        j = 0, index = 0;
		do
		{ 
			index = (2 * j + 1); 
			if (arr[index] < arr[index + 1]) 
            {
				index++; 
            }
			if (arr[j] < arr[index] && index < i) 
			{ 
				int tem1 = arr[j]; 
				arr[j] = arr[index]; 
				arr[index] = tem1; 
			} 
			j = index; 
		
		}while(index < i); 
	} 
} 

int main()
{
    printf("----------------HEAP SORT ITERATIVE-----------------------\n");
    int size = 0,targe = 0;

    printf("Enter size of the array : \n");
    scanf("%d",&size);

    int *arr = (int*)calloc(size,sizeof(int));

    Accept(arr,size);
    Display(arr,size);
    Heap_Sort(arr,size);
    Display(arr,size);
    return 0;
}   