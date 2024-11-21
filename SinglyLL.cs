using System;

class Node
{
    public int data;
    public Node next;

    public Node(int no)
    {
        this.data = no;
        this.next = null;
    }
}

class SinglyLL
{
    public Node first;
    public int iCount;

    public SinglyLL()
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
        }
        iCount++;
    }

    public void DeleteFirst()
    {
        if(first == null)
        {
            Console.WriteLine("Linklist is empty");
            return;
        }

        if(first.next == null)
        {
            first = null;
        }
        else
        {
            first = first.next;
        }
    }

    public void DeleteLast()
    {
        if(first == null)
        {
            Console.WriteLine("Linklist is empty");
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
    }

    public void Display()
    {
        if(first != null)
        {
            Console.WriteLine("Elements of the linklist are : ");
            Node temp = first;

            while(temp != null)
            {
                Console.Write("|"+temp.data+"|->");
                temp = temp.next;
            }
            Console.WriteLine();
        }
        else
        {
            Console.WriteLine("Linklist is empty");
        }
    }
    public int Count()
    {
        return this.iCount;
    }

    public void InsertAtPos(int iPos,int no)
    {
        if((iPos < 1) || (iPos > iCount+1))
        {
            Console.WriteLine("Invalid Position");
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
            Node temp = first;
            Node newn = new Node(no);

            for(int i = 1; i < iPos-1; i++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next = newn;
        }
    }

    public void DeleteAtPos(int iPos)
    {
        if((iPos < 1) || (iPos > iCount))
        {
            Console.WriteLine("Invalid Position");
            return;
        }

        if(iPos == 1)
        {
            DeleteFirst();
        }
        else if(iPos == iCount+1)
        {
            DeleteLast();
        }
        else
        {
            Node temp = first;

            for(int i = 1; i < iPos-1; i++)
            {
                temp = temp.next;
            }
            temp.next = temp.next.next;
        }
    }
}

class MainClass
{
    public static void Main(string[] args)
    {
        SinglyLL obj = new SinglyLL();

        obj.InsertFirst(31);
        obj.InsertFirst(21);
        obj.InsertFirst(11);
        obj.Display();

        obj.InsertLast(111);
        obj.InsertLast(121);
        obj.InsertLast(131);
        obj.Display();

        obj.DeleteFirst();
        obj.DeleteLast();
        obj.Display();

        obj.InsertAtPos(4,51);
        obj.Display();
        obj.DeleteAtPos(4);
        obj.Display();
    }
}