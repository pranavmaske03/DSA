#include<iostream>
using namespace std;

typedef struct Node 
{
    int data;
    struct Node *next;
}NODE,*PNODE;

class Queue 
{
    public:
        PNODE first;
        int iCount;

        Queue();
        ~Queue();

        void Display();
        int Count();
        void Enqueue(int);
        int Dequeue();
};

Queue::Queue()
{
    this->first = NULL;
    this->iCount = 0;
}

Queue::~Queue()
{
    cout<<"Inside Destructor : \n";
}

void Queue::Enqueue(int no)
{
    PNODE newn = new NODE;
    newn->next = NULL;
    newn->data = no;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        PNODE temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    this->iCount++;
}

int Queue::Dequeue()
{
    int value = 0;

    if(first == NULL)
    {
        cout<<"Queue is empty :\n";
        return -1;
    }

    if(first->next == NULL)
    {
        value = first->data;
        delete first;
        first = NULL;
    }
    else 
    {
        PNODE temp = first; 
        value = first->data;
        first = first->next;
        delete temp;
    }
    this->iCount--;
    return value;
}

void Queue::Display()
{
    if(first != NULL)
    {
        cout<<"Elements of the Queue are : \n";
        PNODE temp = first;

        while(temp != NULL)
        {
            cout<<"|"<<temp->data<<"|->";
            temp = temp->next;
        }
        cout<<"|NULL|\n";
    }
    else
    {
        cout<<"Queue is empty : \n";
    }
}

int Queue::Count()
{
    return this->iCount;
}

int main()
{
    Queue obj;

    obj.Enqueue(11);
    obj.Enqueue(12);
    obj.Enqueue(13);
    obj.Enqueue(14);
    obj.Enqueue(15);
    obj.Display();
    cout<<"count of the elements are : "<<obj.Count()<<"\n";

    cout<<"Dequeued element is : "<<obj.Dequeue()<<"\n";
    cout<<"Dequeued element is : "<<obj.Dequeue()<<"\n";
    cout<<"Dequeued element is : "<<obj.Dequeue()<<"\n";
    obj.Display();

    return 0;
}