using System;

class Node
{
    internal int data;
    internal Node next;

    internal Node(int no)
    {
        this.data = no;
        this.next = null;
    }
}

class Stack
{
    public Node first;
    public int iCount;

    public Stack()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void Push(int no)
    {
        Node newn = new Node(no);

        if(first == null)
        {
            first = newn;
        }
        else
        {
            Node temp = first;
            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
        }
        this.iCount++;
    }

    public int Pop()
    {
        int value = 0;

        if(first == null)
        {
            Console.WriteLine("Stack is empty : ");
            return -1;
        }

        if(first.next == null)
        {
            value = first.data;
            first = null;
        }
        else
        {
            Node temp = first;
            while(temp.next.next != null)
            {
                temp = temp.next;
            }
            value = temp.next.data;
            temp.next = null;
        }

        this.iCount--;
        return value;
    }

    public void Display()
    {
        if(first != null)
        {
            Console.WriteLine("Elements of the Stack are : ");
            Node temp = first;

            while(temp != null)
            {
                Console.WriteLine("|"+temp.data+"|");
                temp = temp.next;
            }
        }
        else 
        {
            Console.WriteLine("Stack is empty : ");
        }
    }

    public int Count()
    {
        return this.iCount;
    }
}

class MainClass
{
    public static void Main()
    {
        Stack obj = new Stack();

        obj.Push(11);
        obj.Push(12);
        obj.Push(13);
        obj.Push(14);
        obj.Push(15);
        obj.Display();
        Console.WriteLine("Count of the elements is : "+obj.Count());

        Console.WriteLine("Poped element from stack is : "+obj.Pop());
        Console.WriteLine("Poped element from stack is : "+obj.Pop());

        obj.Display();
        Console.WriteLine("Count of the elements is : "+obj.Count());
    }
}