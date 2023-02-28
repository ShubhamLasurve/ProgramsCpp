//Generic Queue
#include<iostream>
using namespace std;

template <class T> 
struct node
{
    T data;
    struct node *next;
};

template <class T>
class Queue
{
    public:
        struct node<T> * First;
        int iCount;

        Queue();

        bool IsQueueEmpty();
        void EnQueue(T no);       //Insert    Push
        T DeQueue();              //delete    Pop
        void Display();
};

template <class T>
Queue<T> :: Queue()
{
    First = NULL;
    iCount = 0;
}

template <class T>
bool Queue<T> :: IsQueueEmpty()
{
    if(iCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void Queue<T> :: EnQueue(T no)      //InsertLast
{
    struct node<T> * newn = new struct node<T>;

    newn ->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct node<T> * temp = First;

        while(temp->next != NULL)
        {
            temp = temp ->next;
        }
        temp->next = newn;
    }
    iCount++;

    cout<<"Gets pushed in the Queue successfully"<<"\n";
}

template <class T>
T Queue<T> :: DeQueue()              //DeleteFirst
{
    if(First == NULL)
    {
        cout<<"Unable to pop the element as Stack is empty"<<"\n";
        return(T) -1;
    }
    else
    {
        T value = First->data;
        struct node<T> * temp = First;
        First = First->next;
        delete temp;

        iCount--;

        return value;
    }
}

template <class T>
void Queue<T> ::  Display()
{
    if(First == NULL)
    {
        cout<<"Queue is empty"<<"\n";
    }
    else
    {
        cout<<"Elements of Queue are : "<<"\n";

        struct node <T>*temp =First;
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" |->";
            temp = temp -> next;
        }
        cout<<"NULL "<<"\n";
    }
}

int main()
{
    cout<<"------------------------------------------------------------------------------------\n";
    Queue <int>iobj;
    
    iobj.EnQueue(11);
    iobj.EnQueue(21);
    iobj.EnQueue(51);
    iobj.EnQueue(101);

    iobj.Display();

    int iRet = iobj.DeQueue();
    cout<<"DeQueued Element is :"<<iRet<<"\n";

    iRet = iobj.DeQueue();
    cout<<"DeQueued Element is :"<<iRet<<"\n";

    iobj.Display();
    cout<<"------------------------------------------------------------------------------------\n";

    
    return 0;
}