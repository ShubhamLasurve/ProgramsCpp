#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class SinglyLL
{
    public:
        struct node<T> * First;
        int iCount;

        SinglyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPosition(T no ,int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int ipos);

        void Display();
};

template <class T>
SinglyLL <T> :: SinglyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL <T> :: InsertFirst(T no)
{
    struct node<T> * newn = new struct node<T>;

    newn->data = no;
    newn->next =  NULL;

    if(First == NULL) 
    {
        First = newn;
        iCount++;
    }
    else 
    {
        newn->next = First;
        First = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL <T> :: InsertLast(T no)
{
    struct node<T> * newn = new struct node<T>;

    newn->data = no;
    newn->next =  NULL;

    if(First == NULL) 
    {
        First = newn;
        iCount++;
    }
    else 
    {
        struct node<T> * temp = First;

        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL <T>:: InsertAtPosition(T no, int ipos)
{
    if((ipos < 1) || (ipos > iCount+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> * newn = new struct node<T>;

        newn->data = no;
        newn->next = NULL;

        struct node<T> * temp = First;
        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyLL <T>:: DeleteFirst()
{
    if(First == NULL) 
    {
        return;
    }
    else if(First -> next == NULL) 
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        struct node<T> * temp = First;
        First = First -> next;
        delete temp;
        iCount--;
    }
}

template <class T>
void SinglyLL <T>:: DeleteLast()
{    
    if(First == NULL)   
    {
        return;
    }
    else if(First -> next == NULL) 
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        struct node <T>* temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;

        iCount--;
    }
}

template <class T>
void SinglyLL <T>:: DeleteAtPosition(int ipos)
{
    if((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> * temp1 = First;

        for(int iCnt = 1; iCnt < ipos-1;iCnt++)
        {
            temp1 = temp1->next;
        }

        struct node<T> * temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }
}

template <class T>
void SinglyLL <T>:: Display()
{
    cout<<"Elements of Linked List are : "<<"\n";
    struct node<T> * temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

int main()
{
    cout<<"---------------------------------------------------------------------------------------"<<"\n";
    cout<<"Integer Linke List\n";

    SinglyLL<int> iobj;
    
    iobj.InsertFirst(51);
    iobj.InsertFirst(21);
    iobj.InsertFirst(11);

    iobj.Display();
    cout<<"Number of nodes in first linkedlist are : "<<iobj.iCount<<"\n";

    iobj.InsertLast(101);
    iobj.InsertLast(111);
    iobj.InsertLast(121);
    iobj.Display();
    cout<<"Number of nodes in first linkedlist are : "<<iobj.iCount<<"\n";
    
    iobj.InsertAtPosition(105,5);
    iobj.Display();
    cout<<"Number of nodes in first linkedlist are : "<<iobj.iCount<<"\n";

    iobj.DeleteAtPosition(5);
    iobj.Display();
    cout<<"Number of nodes in first linkedlist are : "<<iobj.iCount<<"\n";
    
    iobj.DeleteFirst();
    iobj.DeleteLast();

    iobj.Display();
    cout<<"Number of nodes in first linkedlist are : "<<iobj.iCount<<"\n";

    cout<<"-------------------------------------------------------------------------------------------------------"<<"\n";    

    cout<<"---------------------------------------------------------------------------------------"<<"\n";
    cout<<"Character Linke List\n";

    SinglyLL<char> cobj;
    
    cobj.InsertFirst('c');
    cobj.InsertFirst('b');
    cobj.InsertFirst('a');

    cobj.Display();
    cout<<"Number of nodes in first linkedlist are : "<<cobj.iCount<<"\n";

    cobj.InsertLast('d');
    cobj.InsertLast('e');
    cobj.InsertLast('f');
    cobj.Display();
    cout<<"Number of nodes in first linkedlist are : "<<cobj.iCount<<"\n";
    
    cobj.InsertAtPosition('z',5);
    cobj.Display();
    cout<<"Number of nodes in first linkedlist are : "<<cobj.iCount<<"\n";

    cobj.DeleteAtPosition(5);
    cobj.Display();
    cout<<"Number of nodes in first linkedlist are : "<<cobj.iCount<<"\n";
    
    cobj.DeleteFirst();
    cobj.DeleteLast();

    cobj.Display();
    cout<<"Number of nodes in first linkedlist are : "<<cobj.iCount<<"\n";

    cout<<"-------------------------------------------------------------------------------------------------------"<<"\n";    
    return 0;
}