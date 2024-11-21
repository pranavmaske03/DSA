
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

class CircularLinkedList
{
    private int iCount;
    private Node first;
    private Node last;

    public CircularLinkedList()
    {
        this.iCount = 0;
        this.first = null;
        this.last = null;
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
            first.prev = newn;
            newn.next = first;
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
            Node newn = new Node(no);
            Node temp = first;

            for(int i = 1; i < iPos-1; i++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next = newn;
            iCount++;
        }
    }

    public void DeleteFirst()
    {
        if((first == null) && (last == null))
        {
            System.out.println("Linklist is empty :");
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
        first.prev = last;
        last.next = first;
        iCount--;
    }
    public void DeleteLast()
    {
        if((first == null) && (last == null))
        {
            System.out.println("Linklist is empty :");
            return;
        }

        if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            last = last.prev;
            last.next = null;
        }
        first.prev = last;
        last.next = first;
        iCount--;
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
            Node temp = first;

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
            System.out.println("Elements of the linklist are : ");
            Node temp = first;

            do
            {
                System.out.print("|"+temp.data+"|<=>");
                temp = temp.next;
            }while(temp != last.next);
            System.out.println();
        }
        else
        {
            System.out.println("LinkList is empty :");
        }
    }
    public int Count()
    {
        return this.iCount;
    }
}

class DoublyCL
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