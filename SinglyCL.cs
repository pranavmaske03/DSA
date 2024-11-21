using System;

class NodeC
{
    public int data;
    public NodeC next;

    public NodeC(int no)
    {
        this.data = no;
        this.next = null;
    }
}

abstract class Linkedlist
{
    public int iCount;
    public NodeC first;
    public NodeC last;

    public abstract void InsertFirst(int no);
    public abstract void InsertLast(int no);
    public abstract void InsertAtPos(int iPos,int no);

    public abstract void DeleteFirst();
    public abstract void DeleteLast();
    public abstract void DeleteAtPos(int iPos);

    public void Display()
    {
        if(first != null)
        {
            Console.WriteLine("Elements of the linkedlist are :");
            NodeC temp = first;
            do 
            {
                Console.Write("|"+temp.data+"|-> ");
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

class SinglyCL : Linkedlist
{   
    public SinglyCL()
    {
        this.iCount = 0;
        this.first = null;
        this.last = null;
    }

    public override void InsertFirst(int no)
    {
        NodeC newn = new NodeC(no);

        if((first == null) && (last == null))
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.next = first;
            first = newn;
        }
        last.next = first;
        iCount++;
    }

    public override void InsertLast(int no)
    {
        NodeC newn = new NodeC(no);

        if((first == null) && (last == null))
        {
            this.first = newn;
            this.last = newn;
        }
        else
        {
            last.next = newn;
            last = newn;
        }
        last.next = first;
        iCount++;
    }

    public override void InsertAtPos(int iPos,int no)
    {
        if((iPos < 1) || (iPos > iCount+1))
        {
            Console.WriteLine("Invalid position :");
            return;
        }

        if(iPos == 1)
        {
            this.InsertFirst(no);
        }
        else if(iPos == iCount+1)
        {
            this.InsertLast(no);
        }
        else
        {
            NodeC newn = new NodeC(no);
            NodeC temp = first;

            for(int i = 1; i < iPos-1; i++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next = newn;
            iCount++;
        }
    }

    public override void DeleteFirst()
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
            first = first.next;
            last.next = null;
        }
        last.next = first;
        iCount--;
    }

    public override void DeleteLast()
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
            NodeC temp = first;
            while(temp.next != last)
            {
                temp = temp.next;
            }
            temp.next = null;
            last = temp;
        }
        last.next = first;
        iCount--;
    }

    public override void DeleteAtPos(int iPos)
    {
        if((iPos < 1) || (iPos > iCount))
        {
            Console.WriteLine("Invalid position :");
            return;
        }

        if(iPos == 1)
        {
            this.DeleteFirst();
        }
        else if(iPos == iCount+1)
        {
            this.DeleteLast();
        }
        else
        {
            NodeC temp = first;

            for(int i = 1; i < iPos-1; i++)
            {
                temp = temp.next;
            }
            temp.next = temp.next.next;
            iCount--;
        }
    }
}

class MainClass
{
    static void Main()
    {
        SinglyCL obj = new SinglyCL();
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