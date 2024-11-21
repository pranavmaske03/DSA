
class NodeQ
{
    public int data;
    public NodeQ next;

    public NodeQ(int no)
    {
        this.data = no;
        this.next = null;
    }
}

class Queue_Functions
{
    public NodeQ first;
    public int iCount;

    public Queue_Functions()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void Enqueue(int no)
    {
        NodeQ newn = new NodeQ(no);

        if(first == null)
        {
            first = newn;
        }
        else
        {
            NodeQ temp = first;

            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
        }
        this.iCount++;
    }

    public int Dequeue()
    {
        int value = 0;

        if(first == null)
        {
            System.out.println("Queue is empty :");
            return -1;
        }

        if(first.next == null)
        {
            value = first.data;
            first = null;
        }
        else
        {
            value = first.data;
            first = first.next;
        }
        this.iCount--;
        return value;
    }

    public int Count()
    {
        return this.iCount;
    }

    public void Display()
    {
        if(first != null)
        {
            System.out.println("Elements of the Queue are : ");
            NodeQ temp = first;

            while(temp != null)
            {
                System.out.print("|"+temp.data+"|->");
                temp = temp.next;
            }
        }
        else
        {
            System.out.println("Queue is empty : ");
        }
        System.out.println("|NULL|");
    }
}

class Queue
{
    public static void main(String args[])
    {
        Queue_Functions obj = new Queue_Functions();

        obj.Enqueue(11);
        obj.Enqueue(12);
        obj.Enqueue(13);
        obj.Enqueue(14);
        obj.Enqueue(15);
        obj.Display();
        System.out.println("Count of the elements are : "+obj.Count());

        System.out.println("Dequeued element from queue is : "+obj.Dequeue());
        System.out.println("Dequeued element from queue is : "+obj.Dequeue());

        obj.Display();
        System.out.println("Count of the elements are : "+obj.Count());
    }
}