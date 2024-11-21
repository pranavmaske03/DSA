#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
}NODE,*PNODE;

class Stack
{
    public:
        PNODE first;
        int iCount;

        Stack();
        ~Stack();
        void Push(int);
        int Pop();
        void Display();
        int Count();
};

Stack::Stack()
{
    this->first = NULL;
    this->iCount = 0;
}

Stack::~Stack()
{
    cout<<"Inside Destructor : \n";
    PNODE temp = NULL;

    while(first != NULL)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
}

void Stack::Push(int no)
{
    PNODE newn = new NODE;
    newn->next = NULL;
    newn->data = no;

    if(first == NULL)
    {
        this->first = newn;
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

int Stack::Pop()
{
    int value = 0;

    if(first == NULL)
    {
        cout<<"Stack is empty : \n";
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
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        value = temp->next->data;
        delete temp->next;
        temp->next = NULL;
    }
    this->iCount--;
    return value;
}

void Stack::Display()
{
    if(first != NULL)
    {
        cout<<"Elements of the Stack are : \n";
        PNODE temp = first;

        while(temp != NULL)
        {
            cout<<"|"<<temp->data<<"|\n";
            temp = temp->next;
        }
    }
    else
    {
        cout<<"Stack is empty : \n";
    }
}

int Stack::Count()
{
    return this->iCount;
}

int main()
{
    Stack obj;

    obj.Push(11);
    obj.Push(12);
    obj.Push(13);
    obj.Push(14);
    obj.Push(15);
    obj.Push(16);
    obj.Display();
    int ret = obj.Count();
    cout<<"Count of the Elements is : "<<ret<<"\n";

    cout<<"Poped element from stack is : "<<obj.Pop()<<"\n";
    cout<<"Poped element from stack is : "<<obj.Pop()<<"\n";
    obj.Display();
    ret = obj.Count();
    cout<<"Count of the Elements is : "<<ret<<"\n";    

    return 0;
}