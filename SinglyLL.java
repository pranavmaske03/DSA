import java.util.*;

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

abstract class Linkedlist
{
    protected Node first;
    protected int iCount;

    public abstract void InsertFirst(int no);
    public abstract void InsertLast(int no);

    public abstract void DeleteFirst();
    public abstract void DeleteLast();

    public abstract void InsertAtPos(int iPos,int no);
    public abstract void DeleteAtPos(int iPos);

    public int Count()
    {
        return this.iCount;
    }

    public void Display()
    {
        if(first != null)
        {
            System.out.println("Elements of the linkedlist :");
            Node temp = first;

            while(temp != null)
            {
                System.out.print("|"+temp.data+"|-> ");
                temp = temp.next;
            }
            System.out.println("NULL");
        }
        else
        {
            System.out.println("Linked List is empty :");
        }
    }
}

class SinglyLinkedList extends Linkedlist
{
    
    public SinglyLinkedList()
    {
        this.first = null;
        this.iCount = 0;
    }

    public  void InsertFirst(int no)
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

    public  void InsertLast(int no)
    {
        Node newn = new Node(no);

        if(first == null)
        {
            first.next = newn;
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

    public  void DeleteFirst()
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
        }

        iCount--;
    }

    public  void DeleteLast()
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

    public  void InsertAtPos(int iPos,int no)
    {
        if((iPos < 1) || (iPos > iCount+1))
        {
            System.out.println("Invalid Position.");
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
            temp.next = newn;

            iCount++;
        }
    }

    public  void DeleteAtPos(int iPos)
    {
        if((iPos < 1) || (iPos > iCount))
        {
            System.out.println("Invalid Position.");
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

            iCount--;
        }
    }
}

class SinglyLL
{
    public static void main(String args[])
    {
        SinglyLinkedList obj = new SinglyLinkedList();
        obj.InsertFirst(31);
        obj.InsertFirst(21);
        obj.InsertFirst(11);
        obj.Display();
        System.out.println("Count of the nodes are : "+obj.Count());
        obj.InsertLast(111);
        obj.InsertLast(121);
        obj.InsertLast(131);
        obj.Display();
        System.out.println("Count of the nodes are : "+obj.Count());

        obj.InsertAtPos(4,51);
        obj.Display();
        System.out.println("Count of the nodes are : "+obj.Count());

        obj.DeleteAtPos(4);
        obj.Display();
        System.out.println("Count of the nodes are : "+obj.Count());

        obj.DeleteFirst();
        obj.DeleteLast();
        obj.Display();
        System.out.println("Count of the nodes are : "+obj.Count());
    }
}