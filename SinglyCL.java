
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

interface Linkedlist
{
    public void InsertFirst(int no);
    public void InsertLast(int no);

    public void DeleteFirst();
    public void DeleteLast();

    public void InsertAtPos(int iPos,int no);
    public void DeleteAtPos(int iPos);

    public void Display();
    public int Count();
}

class CircularLinkedList implements Linkedlist
{
    public NodeC first;
    public NodeC last;
    public int iCount;

    public CircularLinkedList()
    {
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }
    
    public void InsertFirst(int no)
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
        this.iCount++;
    }

    public void InsertLast(int no)
    {
        NodeC newn = new NodeC(no);

        if(first == null)
        {
            first = newn;
        }
        else
        {   
            last.next = newn;
            last = newn;
        }
        last.next = first;
        this.iCount++;
    }

    public void DeleteFirst()
    {
        if(first == null)
        {
            System.out.println("LinkedList is empty :");
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
            last.next = null;
        }
        last.next = first;
        this.iCount--;
    }

    public void DeleteLast()
    {
        if(first == null)
        {
            System.out.println("LinkedList is empty :");
            return;
        }

        if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            NodeC temp = first;
            while(temp.next != last)
            {
                temp = temp.next;
            }
            last = temp;
            last.next = null;
        }
        last.next = first;
        this.iCount--;   
    }

    public void InsertAtPos(int iPos,int no)
    {
        if((iPos < 1) || (iPos > iCount+1))
        {
            System.out.println("Invalid position...");
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
    public void DeleteAtPos(int iPos)
    {
        if((iPos < 1) || (iPos > iCount))
        {
            System.out.println("Invalid position...");
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

    public void Display()
    {
        if((first != null) && (last != null))
        {
            System.out.println("Elements of the linklist are :");
            NodeC temp = first;

            do 
            {
                System.out.print("|"+temp.data+"|-> ");
                temp = temp.next;
            }while(temp != last.next);
            System.out.println();
        }
        else
        {
            System.out.println("Linkedlist is empty...");
        }
    }
    public int Count()
    {
        return this.iCount;
    }
}

class SinglyCL
{
    public static void main(String args[])
    {
        CircularLinkedList obj = new CircularLinkedList();
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