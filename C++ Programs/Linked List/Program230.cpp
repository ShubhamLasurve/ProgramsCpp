//Doubly LL
#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
    struct node *prev;      // X
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class DoublyLL 
{
    public:
        PNODE First;

        DoublyLL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();
};

DoublyLL :: DoublyLL()
{
    First = NULL;
}

void DoublyLL :: InsertFirst(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      // X

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        (First)->prev = newn;  // X

        First = newn;
    }
}

void DoublyLL :: InsertLast(int no)
{
    PNODE newn = new NODE;
    PNODE temp = First;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      // X

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;      // X
    }
}

void DoublyLL :: Display()
{
    cout<<"Elements of the Linked List are :"<<"\n";

    cout<<"NULL<=> ";

    while(First != NULL)
    {
        cout<<"| "<<First->data<<" |<=>";
        First = First->next;
    }
    cout<<"NULL"<<"\n";
}

int DoublyLL :: Count()
{
    PNODE temp = First;
    int iCnt = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }

    return iCnt;
}

void DoublyLL :: DeleteFirst()
{
    PNODE temp = First;
    if(First == NULL)      //LL is empty
    {
        return;
    }
    else if((First)->next == NULL)     //LL contains 1 element
    {
        delete(First);
        First = NULL;
    }
    else                //LL contains more than one elements
    {
        (temp) = (temp) -> next;
        delete(temp->prev);       //X
        (temp)->prev = NULL;      //X
    }
}

void DoublyLL :: DeleteLast()
{
    PNODE temp = First;

    if(First == NULL)      //LL is empty
    {
        return;
    }
    else if((First)->next == NULL)     //LL contains 1 element
    {
        delete(First);
        First = NULL;
    }
    else                //LL contains more than one elements
    {
        while(temp -> next -> next != NULL)
        {
            temp = temp ->next;
        }
        delete(temp-> next);
        temp ->next = NULL;
    }
}

void DoublyLL :: InsertAtPos(int no,int iPos)
{
    int NodeCnt = 0;
    int iCnt = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    NodeCnt = Count();


    if((iPos < 1) || (iPos > (NodeCnt + 1)))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == (NodeCnt + 1))
    {
        InsertLast(no);
    }
    else
    {
        newn = new NODE;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;      //X

        temp = First;

        for(iCnt = 1;iCnt < (iPos - 1);iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next -> prev = newn;        //X
        temp -> next = newn;
        newn -> prev = temp;                //X

    }
}

void DoublyLL :: DeleteAtPos(int iPos)
{
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;
    int iCnt = 0;
    int NodeCnt = 0;

    NodeCnt = Count();

    if((iPos < 1) || (iPos > NodeCnt))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == NodeCnt)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for(iCnt = 1;iCnt < (iPos - 1);iCnt++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1 -> next; 
        temp1 ->next = temp2->next;
        delete(temp2);
    }
}

int main()
{
    PNODE Head = NULL;
    int iRet = 0;

    DoublyLL obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.InsertLast(111);

    obj.InsertLast(121);
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    obj.InsertAtPos(105,5);
    obj.Display();

    obj.DeleteAtPos(5);
    obj.Display();
    
    obj.DeleteFirst();
    obj.DeleteLast();

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    return 0;
}