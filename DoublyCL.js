
class NodeCL
{
    data;
    next;
    prev;
    constructor(data)
    {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

class DoublyCL
{
    #first;
    #last;
    #iCount;

    constructor()
    {
        this.#first = null;
        this.#last = null;
        this.#iCount = 0;
    }

    InsertFirst(no)
    {
        var newn = new NodeCL(no);

        if(this.#first == null && this.#last == null)
        {
            this.#first = newn;
            this.#last = newn;
        }
        else 
        {
            this.#first.prev = newn;
            newn.next = this.#first;
            this.#first = newn;
        }
        this.#first.prev = this.#last;
        this.#last.next = this.#first;
        this.#iCount++;
    }

    InsertLast(no)
    {
        var newn = new NodeCL(no);

        if(this.#first == null && this.#last == null)
        {
            this.#first = newn;
            this.#last = newn;
        }
        else
        {
            newn.prev = this.#last;
            this.#last.next = newn;
            this.#last = newn;
        }
        this.#first.prev = this.#last;
        this.#last.next = this.#first;
        this.#iCount++;
    }

    InsertAtPos(no,iPos)
    {
        if(iPos < 1 || iPos > this.Count()+1)
        {
            console.log("Invalid position");
            return;
        }

        if(iPos == 1)
        {
            this.InsertFirst(no);
        }
        else if(iPos == this.Count()+1)
        {
            this.InsertLast(no);
        }
        else
        {
            var newn = new NodeCL(no);
            var temp = this.#first;
            for(var i = 1; i < iPos-1; i++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next.prev = newn;
            temp.next = newn;
            newn.prev = temp;

            this.#first.prev = this.#last;
            this.#last.next = this.#first;
            this.#iCount++;
        }
    }

    DeleteFirst()
    {
        if(this.#first == null && this.#last == null)
        {
            return;
        }
        if(this.#first == this.#last)
        {
            this.#first = null;
            this.#last = null;
        }
        else
        {
            this.#first = this.#first.next;
        }
        this.#first.prev = this.#last;
        this.#last.next = this.#first;
        this.#iCount--;
    }

    DeleteLast()
    {
        if(this.#first == null && this.#last == null)
        {
            return;
        }
        if(this.#first == this.#last)
        {
            this.#first = null;
            this.#last = null;
        }
        else
        {
           this.#last = this.#last.prev;
        }
        this.#iCount--;
    }

    DeleteAtPos(iPos,no)
    {
        if(iPos < 1 || iPos > this.Count())
        {
            console.log("Invalid position");
            return;
        }

        if(iPos == 1)
        {
            this.DeleteFirst();
        }
        else if(iPos == this.Count())
        {
            this.DeleteLast();
        }
        else
        {
           
            var temp = this.#first;
            for(var i = 1; i < iPos-1; i++)
            {
                temp = temp.next;
            }
            temp.next = temp.next.next;
            temp.next.prev = temp;
            this.#iCount--;
        }
    }

    Display()
    {
        if(this.#first != null && this.#last != null)
        {
            console.log("Elements of the linked list are : ");
            var temp = this.#first;
            var disp = "";

            do 
            {
                disp = disp + "| "+temp.data+" |<=>";
                temp = temp.next;
            }while(temp != this.#last.next);
            console.log(disp);
        }
        else
        {
            console.log("Linked List is empty : ");
        }
    }

    Count()
    {
        return this.#iCount;
    }
}

function main()
{
    var obj = new DoublyCL();

    obj.InsertFirst(31);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();
    console.log("Count of the nodes are : "+obj.Count());

    obj.InsertLast(111);
    obj.InsertLast(121);
    obj.InsertLast(131);
    obj.Display();
    console.log("Count of the nodes are : "+obj.Count());

    obj.InsertAtPos(51,4);
    obj.Display();
    console.log("Count of the nodes are : "+obj.Count());

    obj.DeleteAtPos(4);
    obj.Display();
    console.log("Count of the nodes are : "+obj.Count());

    obj.DeleteFirst();
    obj.DeleteLast();
    obj.Display();
    console.log("Count of the nodes are : "+obj.Count());
}

main();