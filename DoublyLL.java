
class Node 
{
    int data;
    Node next;
    Node prev;

    public Node(int no)
    {
        this.data = no;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLinkedlist
{
    public Node first;
    public int iCount;

    public DoublyLinkedlist()
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
                temp  = temp.next;
            }
            temp.next = newn;
            newn.prev = temp;
        }
        iCount++;
    }
    public void InsertAtPos(int iPos,int no)
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

            for(int iCnt = 1; iCnt < iPos-1; iCnt++)
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
        if(first == null)
        {
            Display();
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
            Display();
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
    public void DeleteAtPos(int iPos)
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

            for(int iCnt = 1; iCnt < iPos-1; iCnt++)
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
        if(first != null)
        {
            System.out.println("Elements of the linkedlist are :");
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
            System.out.println("Linklist is empty");
        }
    }
    public int Count()
    {
        return this.iCount;
    }
}

class DoublyLL
{
    public static void main(String args[])
    {   
        DoublyLinkedlist obj = new DoublyLinkedlist();
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