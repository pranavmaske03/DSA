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

interface linklist
{
    void InsertFirst(int no);
    void InsertLast(int no);
    void InsertAtPos(int iPos,int no);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

    void Display();
    int Count();
}

class DoublyCL : linklist
{
    private Node first;
    private Node last;
    private int iCount;

    public DoublyCL()
    {
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {
        Node newn = new Node(no);

        if((first == null) && (last == null))
        {
            this.first = newn;
            this.last = newn;
        }
        else
        {
            newn.next = first;
            first.prev = newn;
            first = newn;
        }
        first.prev = last;
        last.next = first;
        iCount++;
    }

    public void InsertLast(int no)
    {
        Node newn = new Node(no);

        if((first == null) && (last == null))
        {
            this.first = newn;
            this.last = newn;
        }
        else
        {
            last.next = newn;
            newn.prev = last;
            last = newn;
        }
        first.prev = last;
        last.next = first;
        iCount++;
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

    public void DeleteFirst()
    {
        if((first == null) && (last == null))
        {
            Console.WriteLine("Linklist is empty :");
            return;
        }

        if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            first = first.next;
            first.prev = null;
        }
        first.prev = last;
        last.next = first;
        iCount--;
    }

    public void DeleteLast()
    {
         if(first == null && last == null)
        {
            Console.WriteLine("Invalid position :");
            return;
        }

        if(first == last)
        {
            this.first = null;
            this.last = null;
        }
        else
        {
           last = last.prev;
           last.next = null;
        }
        last.next = first;
        first.prev = last;

        iCount--;
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

    public void Display()
    {
        if((first != null) && (last != null))
        {
            Console.WriteLine("Elements of the linklist are :");
            Node temp = first;

            do 
            {
                Console.Write("|"+temp.data+"|<=>");
                temp = temp.next;
            }while(temp != last.next);
            Console.WriteLine();
        }
    }

    public int Count()
    {
        return this.iCount;
    }
}

class MainClass
{
    static void Main()
    {
        DoublyCL obj = new DoublyCL();
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