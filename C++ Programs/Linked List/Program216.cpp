//Doubly Circular LL
#include<iostream>
using namespace std;

#pragma pack(1)   
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class DoublyCircularLL
{
    public:
        PNODE First;
        PNODE Last;

        DoublyCircularLL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();
};

DoublyCircularLL :: DoublyCircularLL()      //Default Constructor
{
    First = NULL;
    Last = NULL;
}

void DoublyCircularLL ::  InsertFirst(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL)) // LL is empty
    {
        First = newn;
        Last = newn;
    }
    else    // If LL contains one or more nodes
    {
        newn->next = First;
        First->prev = newn;
        First = newn; 
    }

    First->prev = Last;
    Last->next = First;
}

void DoublyCircularLL :: InsertLast(int no)
{
    PNODE newn = new NODE; 

    newn->data = no;
    newn->next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL)) // LL is empty
    {
        First = newn;
        Last = newn;
    }
    else    // If LL contains one or more nodes
    {
        (Last) -> next = newn;
        newn->prev = Last;
        Last = newn;
    }

    (First)->prev = Last;
    (Last)->next = First;
}

void DoublyCircularLL :: Display()
{
    PNODE temp = First;
    if(First == NULL && Last == NULL)
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }

    cout<<"Elements of Linked list are : "<<"\n";
    do
    {
        cout<<"| " <<temp->data<<" |<=> ";
        temp = temp -> next;
    }while(temp != Last->next);

    cout<<"\n";
}

int DoublyCircularLL :: Count()
{
    PNODE temp = First;
    int iCnt = 0;

    if(First == NULL && Last == NULL)
    {
        return iCnt;
    }

    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);

    return iCnt;
}

void DoublyCircularLL :: DeleteFirst()
{
    if(First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node
    {
        //free(*First);
        delete First;
        First = NULL;
        Last= NULL;
    }
    else    // More than one node
    {
        (First) = (First) ->next;
        //free((*Last)->next);        // free((*First)->prev);
        delete (Last)->next;

        (First)->prev = Last;
        (Last)->next = First;
    }
}

void DoublyCircularLL :: DeleteLast()
{
    if(First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node
    {
        //free(*First);
        delete First;
        First = NULL;
        Last= NULL;
    }
    else    // More than one node
    {
        Last = (Last) -> prev;
        //free((*First)->prev);       // free((*Last)->next);
        delete (First)->prev;

        (First)->prev = Last;
        (Last)->next = First;
    }
}

void DoublyCircularLL :: InsertAtPos(int no, int ipos)
{
    int  iNodeCnt = Count();
    PNODE newn = NULL;
    PNODE temp = NULL;
    int iCnt = 0;

    if((ipos < 1) || (ipos > iNodeCnt+1))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iNodeCnt +1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new NODE;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;
        for(iCnt = 1;iCnt < ipos - 1;iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }
    
}

void DoublyCircularLL :: DeleteAtPos(int ipos)
{
    int  iNodeCnt = Count();
    PNODE temp = NULL;
    int iCnt = 0;

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCnt +1)
    {
        DeleteLast();
    }
    else
    {
        temp = First;
        for(iCnt = 1;iCnt < ipos - 1;iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete (temp->next->prev);
        temp->next->prev = temp;
    }
    
}

int main()
{
    int iRet = 0;

    DoublyCircularLL obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    
    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes after Insert are : "<<iRet<<"\n";

    obj.InsertAtPos(105,5);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes after InsertAtPos are : "<<iRet<<"\n";

    obj.DeleteAtPos(5);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes after DeleteAtPos are : "<<iRet<<"\n";

    obj.DeleteFirst();
    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes after delete are : "<<iRet<<"\n";

    return 0;
}