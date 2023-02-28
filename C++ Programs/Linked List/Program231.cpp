//Doubly LL
#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;      // X
};

template <class T>
class DoublyLL 
{
    public:
        struct node<T> * First;
        
        DoublyLL();
        int iCount;

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
};

template <class T>
DoublyLL <T>:: DoublyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL <T>:: InsertFirst(T no)
{
    struct node <T> * newn = new struct node<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      // X

    if(First == NULL)
    {
        First = newn;
        iCount++;
    }
    else
    {
        newn->next = First;
        (First)->prev = newn;  // X

        First = newn;
        iCount++;
    }
}

template <class T>
void DoublyLL <T>:: InsertLast(T no)
{
    struct node <T> * newn = new struct node<T>;
    struct node <T> *  temp = First;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      // X

    if(First == NULL)
    {
        First = newn;
        iCount++;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;      // X
        iCount++;
    }
}

template <class T>
void DoublyLL <T>:: Display()
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

template <class T>
void DoublyLL <T>:: DeleteFirst()
{
    struct node <T> *  temp = First;
    if(First == NULL)      //LL is empty
    {
        return;
    }
    else if((First)->next == NULL)     //LL contains 1 element
    {
        delete(First);
        First = NULL;
        iCount--;
    }
    else                //LL contains more than one elements
    {
        (temp) = (temp) -> next;
        delete(temp->prev);       //X
        (temp)->prev = NULL;      //X
        iCount--;
    }
}

template <class T>
void DoublyLL <T>:: DeleteLast()
{
    struct node <T> *  temp = First;

    if(First == NULL)      //LL is empty
    {
        return;
    }
    else if((First)->next == NULL)     //LL contains 1 element
    {
        delete(First);
        First = NULL;
        iCount--;
    }
    else                //LL contains more than one elements
    {
        while(temp -> next -> next != NULL)
        {
            temp = temp ->next;
        }
        delete(temp-> next);
        temp ->next = NULL;
        iCount--;
    }
}

template <class T>
void DoublyLL <T>:: InsertAtPos(T no,int iPos)
{
    int iCnt = 0;
    struct node <T> *  newn = NULL;
    struct node <T> *  temp = NULL;

    if((iPos < 1) || (iPos > (iCount + 1)))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == (iCount + 1))
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct node<T> ;

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
        iCount++;

    }
}

template <class T>
void DoublyLL <T>:: DeleteAtPos(int iPos)
{
    struct node <T> * temp1 = NULL;
    struct node <T> * temp2 = NULL;
    int iCnt = 0;


    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position"<<"\n";
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
        temp1 = First;

        for(iCnt = 1;iCnt < (iPos - 1);iCnt++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1 -> next; 
        temp1 ->next = temp2->next;
        delete(temp2);
        iCount--;
    }
}

int main()
{
    DoublyLL<int> iobj;

    iobj.InsertFirst(51);
    iobj.InsertFirst(21);
    iobj.InsertFirst(11);

    iobj.InsertLast(101);
    iobj.InsertLast(111);

    iobj.InsertLast(121);
    iobj.InsertAtPos(105,5);
    iobj.Display();

    cout<<"Number of elements after Insert are : "<<iobj.iCount<<"\n";

    iobj.DeleteFirst();
    iobj.DeleteLast();
    iobj.DeleteAtPos(5);
    iobj.Display();
    
    cout<<"Number of elements after Delete are : "<<iobj.iCount<<"\n";

    return 0;
}