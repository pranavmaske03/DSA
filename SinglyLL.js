
class NodeSL
{
    data;
    next;
    constructor(data)
    {
        this.data = data;
        this.next = null;
    }
}

class SinglyLL
{
    #first;
    #iCount;

    constructor()
    {
        this.#first = null;
        this.#iCount = 0;
    }

    InsertFirst(no) 
    {
        var newn = new NodeSL(no);

        if(this.#first == null)
        {
            this.#first = newn;
        }
        else
        {
            newn.next = this.#first;
            this.#first = newn;
        }
        this.#iCount++;
    }

    InsertLast(no)
    {
        var newn = new NodeSL(no);

        if(this.#first == null)
        {
            this.#first = newn;
        }
        else
        {
            var temp = this.#first;
            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
        }
        this.#iCount++;
    }

    DeleteFirst()
    {
        if(this.#first == null)
        {
            console.log("Linked list is empty :");
            return;
        }

        if(this.#first.next == null)
        {
            this.#first = null;
        }
        else
        {
            this.#first = this.#first.next;
        }
        this.#iCount--;
    }

    DeleteLast()
    {
        if(this.#first == null)
        {
            console.log("Linked list is empty :");
            return;
        }

        if(this.#first.next == null)
        {
            this.#first = null;
        }
        else
        {
            var temp = this.#first;
            while(temp.next.next != null)
            {
                temp = temp.next;
            }
            temp.next = null;
        }
        this.#iCount--;
    }

    InsertAtPos(no,iPos)
    {
        if((iPos < 1) || (iPos > this.#iCount+1))
        {
            console.log("Invalid position :");
            return;
        }

        if(iPos == 1)
        {
            this.InsertFirst(no);
        }
        else if(iPos == this.#iCount+1)
        {
            this.InsertLast(no);
        }
        else
        {
            var newn = new NodeSL(no);
            var temp = this.#first;

            for(var i = 1; i < iPos-1; i++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next = newn;

            this.#iCount++;
        }
    }

    DeleteAtPos(iPos)
    {
        if((iPos < 1) || (iPos > this.Count()))
        {
            console.log("Invalid position :");
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
            temp.next = temp.next.next   

            this.#iCount--;
        }
    }

    Display()
    {
        var temp = this.#first;
        var disp = "";

        while(temp != null)
        {
            disp = disp + "| "+temp.data+" |->";
            temp = temp.next;
        }
        console.log(disp);
    }

    Count()
    {
        return this.#iCount;
    }
}

function main()
{
    obj = new SinglyLL();

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