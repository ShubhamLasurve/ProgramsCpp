#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class SinglyLL
{
    public:
        //Characteristics
        PNODE First;
        int iCount;

        //Behavioues
        SinglyLL();      //Constructor

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no,int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
};

/*
Return_Value_Class_Name :: Function_Name(Parameters)
{

}
*/

SinglyLL :: SinglyLL()      //Constructor call
{
    First = NULL;
    iCount = 0;
}

void SinglyLL :: InsertFirst(int no)
{
    //Step 1 : Allocate memory for node
    PNODE newn = new NODE;

    //Step 2 : Initilize node
    newn->data = no;
    newn->next = NULL;

    //Step 3 : Check if LL is empty or not 
    if(First == NULL)   //if(iCount == 0)
    {
        First = newn;
        iCount++;
    }
    else    //If LL contains atleast one node
    {
        newn->next = First;
        First = newn;
        iCount++; 
    }

}

void SinglyLL :: InsertLast(int no)
{
    //Step 1 : Allocate memory for node
    PNODE newn = new NODE;

    //Step 2 : Initilize node
    newn->data = no;
    newn->next = NULL;

    //Step 3 : Check if LL is empty or not 
    if(First == NULL)   //if(iCount == 0)
    {
        First = newn;
        iCount++;
    }
    else    //If LL contains atleast one node
    {

    }
}

void SinglyLL :: InsertAtPos(int no, int ipos)
{
    
}

void SinglyLL :: DeleteFirst()
{

}

void SinglyLL :: DeleteLast()
{
    
}

void SinglyLL :: DeleteAtPos(int ipos)
{

}

void SinglyLL :: Display()
{
    cout<<"Elements of Linked List are : "<<"\n";
    PNODE temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

int main()
{
    SinglyLL obj1;
    SinglyLL obj2;

    cout<<sizeof(obj1)<<"\n";
    cout<<"First pointer contains : "<<obj1.First<<"\n";
    cout<<"Number of nodes are : "<<obj1.iCount<<"\n";

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    
    obj1.Display();

    cout<<"Number of nodes in first linked list are : "<<obj1.iCount<<"\n";

//////////////////////////////////////////////////////////////////////

    obj2.InsertFirst(1001);
    obj2.InsertFirst(510);
    obj2.InsertFirst(210);
    obj2.InsertFirst(110);

    obj2.Display();

    cout<<"Number of nodes in Second linked list are : "<<obj2.iCount<<"\n";

    return  0;
}