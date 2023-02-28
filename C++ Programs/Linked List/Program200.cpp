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
        PNODE temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        iCount++;
    }
}

void SinglyLL :: InsertAtPos(int no, int ipos)
{
    
}

void SinglyLL :: DeleteFirst()
{
    if(First == NULL)       //if(iCount == 0)       LL is empty
    {
        return;
    }  
    else if(First->next == NULL)    //else if(iCount == 1)      ll contains 1 node
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else        // If LL contains more than 1 elements
    {
        PNODE temp = First;
        First = First->next;
        delete temp;
        iCount--;
    }
}

void SinglyLL :: DeleteLast()
{
    if(First == NULL)       //if(iCount == 0)       LL is empty
    {
        return;
    }  
    else if(First->next == NULL)    //else if(iCount == 1)      ll contains 1 node
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else        // If LL contains more than 1 elements
    {
        PNODE temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;

        iCount--;

    }
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

    cout<<sizeof(obj1)<<"\n";

    cout<<"Number of nodes are : "<<obj1.iCount<<"\n";

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    
    obj1.Display();

    cout<<"Number of nodes in first linked list are : "<<obj1.iCount<<"\n";

    obj1.InsertLast(101);
    obj1.InsertLast(111);
    obj1.InsertLast(121);

     obj1.Display();

    cout<<"Number of nodes in  linked list after Insert Last are : "<<obj1.iCount<<"\n";

    obj1.DeleteFirst();
    obj1.DeleteLast();

     obj1.Display();

    cout<<"Number of nodes in  linked list after delete operation are : "<<obj1.iCount<<"\n";
    return  0;
}