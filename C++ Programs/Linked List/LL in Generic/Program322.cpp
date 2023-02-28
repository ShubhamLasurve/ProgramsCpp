#include<iostream>
using namespace std;

#pragma pack(1)
template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class SinglyCircularLL
{
    public:
        struct node <T> * First;
        struct node <T> * Last;

        SinglyCircularLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();
};

template <class T>
SinglyCircularLL<T> :: SinglyCircularLL()
{
    First = NULL;
    Last = NULL;
}

template <class T>
void SinglyCircularLL<T> :: InsertFirst(T no)
{
    struct node <T> * newn = new struct node<T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else 
    {
        newn->next = First;
        First = newn;
        (Last)->next = First;
    }
}

template <class T>
void SinglyCircularLL<T> :: InsertLast(T no)
{
    struct node <T> * newn = new struct node<T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL)) 
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else  
    {
        (Last) -> next = newn;
        Last = newn;
        (Last)->next = First;
    }
}

template <class T>
void SinglyCircularLL<T> :: Display()
{
    struct node <T> * temp = First;

    cout<<"Elements of Linked list are :";

    do
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp -> next;
    }while(temp != Last->next);
    cout<<"NULL\n";
}

template <class T>
int SinglyCircularLL<T> :: Count()
{
    struct node <T> * temp = First;
    int iCnt = 0;
    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);
    return iCnt;
}

template <class T>
void SinglyCircularLL<T> :: DeleteFirst()
{
    struct node <T> * temp = First;

    if((First == NULL) && (Last == NULL)) 
    {
        return;
    }
    else if(First == Last) 
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else   
    {
        First = (First)->next;
        delete temp;
        (Last) ->next = First;
    }
}

template <class T>
void SinglyCircularLL<T> :: DeleteLast()
{
    struct node <T> * temp = First;

    if((First == NULL) && (Last == NULL)) 
    {
        return;
    }
    else if(First == Last)   
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else   
    {
        while(temp->next != (Last))
        {
            temp = temp -> next;
        }

        delete temp->next;
        Last = temp; 
        (Last) ->next = First;
    }
}

template <class T>
void SinglyCircularLL <T>:: InsertAtPos(T no, int ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    struct node <T> * newn = NULL;
    struct node <T> * temp = First;

    if((ipos < 1) || (ipos > iNodeCnt + 1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iNodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct node <T>; 
        
        newn->data = no;
        newn->next = NULL;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

template <class T>
void SinglyCircularLL<T> :: DeleteAtPos(int ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    struct node <T> * temp1 = First;
    struct node <T> * temp2 = NULL;

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }   
        temp2 = temp1 ->next;

        temp1->next = temp2->next;
        delete temp2;
    }
}

int main()
{
    cout<<"------------------------------------------------------------------------------------------------\n";
    cout<<"Integer Linked List\n";

    SinglyCircularLL <int>iobj;

    int iRet = 0;
    
    iobj.InsertFirst(51);
    iobj.InsertFirst(21);
    iobj.InsertFirst(11); 
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of elements after InsertFirst are : "<<iRet<<"\n";

    iobj.InsertLast(101);
    iobj.InsertLast(111);
    iobj.InsertLast(121);
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of elements after InsertLast are : "<<iRet<<"\n";

    iobj.InsertAtPos(105,5);
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of elements after insertAtPos are : "<<iRet<<"\n";

    iobj.DeleteAtPos(5);
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of elements after DeleteAtPos are : "<<iRet<<"\n";

    iobj.DeleteFirst();
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of elements after Delete First are : "<<iRet<<"\n";

    iobj.DeleteLast();
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of elements DeleteLast are : "<<iRet<<"\n";
    cout<<"---------------------------------------------------------------------------------------------------\n";

    cout<<"------------------------------------------------------------------------------------------------\n";
    cout<<"Character Linked List\n";

    SinglyCircularLL <char>cobj;
    
    cobj.InsertFirst('c');
    cobj.InsertFirst('b');
    cobj.InsertFirst('a');
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of elements after InsertFirst are : "<<iRet<<"\n";
    
    cobj.InsertLast('d');
    cobj.InsertLast('e');
    cobj.InsertLast('f');
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of elements after InsertLast are : "<<iRet<<"\n";

    cobj.InsertAtPos('z',5);
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of elements after InsertAtPos are : "<<iRet<<"\n";

    cobj.DeleteAtPos(5);
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of elements after DeleAtPos are : "<<iRet<<"\n";

    cobj.DeleteFirst();
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of elements after DeleteFirst are : "<<iRet<<"\n";

    cobj.DeleteLast();
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";
    cout<<"---------------------------------------------------------------------------------------------------\n";

    return 0;
}