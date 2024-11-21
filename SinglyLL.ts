

class NodeSL
{
    public data : number;
    public next : NodeSL;

    constructor(no : number)
    {
        this.data = no;
        this.next = null;
    }
}

interface linkedlist
{
    InsertFirst(no : number) : void;
    InsertLast(no : number) : void;
    InsertAtPos(no : number,iPos : number) : void;

    DeleteFirst() : void;
    DeleteLast() : void;
    DeleteAtPos(iPos : number) : void;

    Display() : void;
    Count() : number;
}

class SinglyLL implements linkedlist
{
    public first : NodeSL;
    public iCount : number;

    constructor()
    {
        this.first = null;
        this.iCount = 0;
    }

    InsertFirst(no : number) : void
    {
        var newn = new NodeSL(no);

        if(this.first == null)
        {
            this.first = newn;
        }
        else
        {
            newn.next = this.first;
            this.first = newn;
        }
        this.iCount++;
    }

    InsertLast(no : number) : void
    {
        var newn = new NodeSL(no);

        if(this.first == null)
        {
            this.first = newn;
        }
        else
        {
            var temp : NodeSL = this.first;

            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
        }
        this.iCount++;
    }

    InsertAtPos(no : number,iPos : number) : void
    {
        if((iPos < 1) || (iPos > this.iCount+1))
        {
            console.log("Invalid postion");
            return;
        }

        if(iPos == 1)
        {
            this.InsertFirst(no);
        }
        else if(iPos == this.iCount+1)
        {
            this.InsertLast(no);
        }
        else
        {
            var newn = new NodeSL(no);
            var temp : NodeSL =  this.first;

            for(var i = 1; i < iPos -1; i++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next = newn;
            this.iCount++;
        }
    }

    DeleteFirst() : void
    {
        if(this.first == null)
        {
            this.Display();
            return;
        }

        if(this.first.next == null)
        {
            this.first = null;
        }
        else
        {
            this.first = this.first.next;
        }
        this.iCount--;
    }

    DeleteLast() : void
    {
        if(this.first == null)
        {
            this.Display();
            return;
        }

        if(this.first.next == null)
        {
            this.first = null;
        }
        else
        {
            var temp : NodeSL = this.first;

            while(temp.next.next != null)
            {
                temp = temp.next;
            }
            temp.next = null;
        }
        this.iCount--;
    }

    DeleteAtPos(iPos : number) : void
    {
        if((iPos < 1) || (iPos > this.iCount))
        {
            console.log("Invalid postion");
            return;
        }

        if(iPos == 1)
        {
            this.DeleteFirst();
        }
        else if(iPos == this.iCount+1)
        {
            this.DeleteLast();
        }
        else
        {
            var temp : NodeSL =  this.first;

            for(var i = 1; i < iPos -1; i++)
            {
                temp = temp.next;
            }
            temp.next = temp.next.next;
            this.iCount--;
        }
    }

    Display() : void
    {
        if(this.first != null)
        {
            console.log("Elements of the linked list are :");
            var temp : NodeSL = this.first;
            var disp = "";

            while(temp != null)
            {
                disp = disp + "|"+temp.data+"|-> "
                temp = temp.next;
            }
            console.log(disp);
        }
        else
        {
            console.log("Linkedlist is empty :");
        }
    }

    Count() : number
    {
        return this.iCount;
    }
}

function main()
{
    var obj = new SinglyLL();
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

main()