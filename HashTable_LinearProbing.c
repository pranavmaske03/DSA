#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 10

int hashtable[SIZE];

void init()
{
    for(int i = 0; i < SIZE; i++)
    {
        hashtable[i] = -1;
    }
}

int hash(int key)
{
    return key % SIZE;
}

void insert(int key)
{
    int index = hash(key);

    if (hashtable[index] == -1)
    {
        hashtable[index] = key;
        printf("Key %d inserted at index %d\n", key, index);
    }
    else
    {
        int i = (index + 1) % SIZE;
        while(i != index)
        {
            if(hashtable[i] == -1)
            {
                hashtable[i] = key;
                printf("Key %d inserted at index %d (collision resolved using linear probing)\n", key, i);
                return;
            }
            i = (i + 1) % SIZE;
        }
        printf("Hash table is full, cannot insert %d\n", key);
    }
}                                                                                                    

int Search(int key)
{
    int index = hash(key);
    int i = index;

    while (hashtable[i] != -1)
    {
        if (hashtable[i] == key)
        {
            return i;
        }
        i = (i + 1) % SIZE;
        if (i == index)
        {
            break;
        }
    }
    return -1;
}

void display()
{
    printf("Hash Table :\n");
    for (int i = 0; i < SIZE; i++)
    {
        if(hashtable[i] != -1)
        {
            printf("%d\t", hashtable[i]);
        }
    }
    printf("\n");
}

void Delete(int element)
{
    int loc = Search(element);
    if(loc != -1)
    {
        hashtable[loc] = -1;
    }
    else
    {
        printf("Element not found..\n");
    }
}

int main()
{
    int choice, key;

    init();

    printf("\n----------------------------------------------------------------------\n");
    printf("HASH TABLE OPERATIONS.\n");
    printf("----------------------------------------------------------------------\n");

    while(true)
    {  
        printf("\n-----------------------------------------------------------------------\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Delete\n");
        printf("0. Exit\n");
        printf("-----------------------------------------------------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                int index = Search(key);
                if (index == -1)
                {
                    printf("Key %d not found\n", key);
                }
                else
                {
                    printf("Key %d found at index %d\n", key, index);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Enter element to delete : \n");
                scanf("%d",&key);
                Delete(key);
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}