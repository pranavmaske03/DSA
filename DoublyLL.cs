using System;

class Node
{
    public int data;
    public Node next;
    public Node prev;

    public Node(int no)
    {
        this.data = no;
        this.next = null;
        this.prev = null;
    }
}

interface Linkedlist
{
    void InsertFirst(int no);
    void InsertLast(int no);
    void Display();
    int Count();
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(int iPos,int no);
    void DeleteAtPos(int iPos);
}

class DoublyLL : Linkedlist
{
    public Node first;
    public int iCount;

    public DoublyLL()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {
        Node newn = new Node(no);

        if(first == null)
        {
            first = newn;
        }
        else
        {
            newn.next = first;
            first.prev = newn;
            first = newn;
        }
        iCount++;
    }

    public void InsertLast(int no)
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
            newn.prev = temp;
        }
        iCount++;
    }

    public void Display()
    {
        if(first != null)
        {
            Node temp = first;
            while(temp != null)
            {
                Console.Write("|"+temp.data+"|<=> ");
                temp = temp.next;
            }
            Console.WriteLine("NULL");
        }
        else
        {
            Console.WriteLine("Linked List is empty ");
        }
    }

    public int Count()
    {
        return this.iCount;
    }

    public void DeleteFirst()
    {
        if(first == null)
        {
            return;
        }

        if(first.next == null)
        {
            first = null;
        }
        else
        {
            first = first.next;
            first.prev = null;
        }
        iCount--;
    }

    public void DeleteLast()
    {
        if(first == null)
        {
            return;
        }

        if(first.next == null)
        {
            first = null;
        }
        else
        {
            Node temp = first;

            while(temp.next.next != null)
            {
                temp = temp.next;
            }
            temp.next = null;
        }
        iCount--;
    }

    public void InsertAtPos(int iPos,int no)
    {
        if((iPos < 1) || (iPos > iCount+1))
        {
            Console.WriteLine("Invalid Position.");
            return;
        }

        if(iPos == 1)
        {
            InsertFirst(no);
        }
        else if(iPos == iCount+1)
        {
            InsertLast(no);
        }
        else
        {
            Node newn = new Node(no);
            Node temp = first;

            for(int iCnt = 1; iCnt < iPos -1; iCnt++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next.prev = newn;
            temp.next = newn;
            newn.prev = temp;

            iCount++;
        }
    }

    public void DeleteAtPos(int iPos)
    {
        if((iPos < 1) || (iPos > iCount))
        {
            Console.WriteLine("Invalid Position.");
            return;
        }

        if(iPos == 1)
        {
            DeleteFirst();
        }
        else if(iPos == iCount)
        {
            DeleteLast();
        }
        else
        {
            Node temp = first;

            for(int iCnt = 1; iCnt < iPos -1; iCnt++)
            {
                temp = temp.next;
            }
            temp.next = temp.next.next;
            temp.next.prev = temp;

            iCount--;
        }
    }
}

class MainClass
{
    static void Main()
    {
        DoublyLL obj = new DoublyLL();
        obj.InsertFirst(31);
        obj.InsertFirst(21);
        obj.InsertFirst(11);
        obj.Display();
        Console.WriteLine("Count of the nodes are : "+obj.Count());
        obj.InsertLast(111);
        obj.InsertLast(121);
        obj.InsertLast(131);
        obj.Display();
        Console.WriteLine("Count of the nodes are : "+obj.Count());

        obj.InsertAtPos(4,51);
        obj.Display();
        System.Console.WriteLine("Count of the nodes are : "+obj.Count());

        obj.DeleteAtPos(4);
        obj.Display();
        Console.WriteLine("Count of the nodes are : "+obj.Count());

        obj.DeleteFirst();
        obj.DeleteLast();
        obj.Display();
        Console.WriteLine("Count of the nodes are : "+obj.Count());
    }
}