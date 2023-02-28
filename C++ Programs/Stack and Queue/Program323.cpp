//Generic Stack
#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class Stack
{
    public:
        struct node<T> *First;
        int iCount;

        Stack();

        bool IsStackEmpty();
        void Push(T no);      //Insert
        T Pop();              //delete
        void Display();
};

template <class T>
Stack <T>:: Stack()
{
    First = NULL;
    iCount = 0;
}

template <class T>
bool Stack<T> :: IsStackEmpty()
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
void Stack <T>:: Push(T no)      //InsertFirst
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
        newn->next = First;
        First = newn;
    }
    iCount++;

    cout<<"Gets pushed in the stack successfully"<<"\n";
}

template <class T>
T Stack <T>:: Pop()              //DeleteLast
{
    if(First == NULL)
    {
        cout<<"Unable to pop the element as Stack is empty"<<"\n";
        return -1;
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
void Stack<T> ::  Display()
{
    if(First == NULL)
    {
        cout<<"Stack is empty"<<"\n";
    }
    else
    {
        cout<<"Elements of Stack are : "<<"\n";

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
    
    Stack<int> iobj;
    
    iobj.Push(11);
    iobj.Push(21);
    iobj.Push(51);
    iobj.Push(101);

    iobj.Display();

    int iRet = iobj.Pop();
    cout<<"1st Poped Element is :"<<iRet<<"\n";

    iRet = iobj.Pop();
    cout<<"2nd Poped Element is :"<<iRet<<"\n";

    iobj.Display();
    cout<<"------------------------------------------------------------------------------\n";

    Stack<char> cobj;
    
    cobj.Push('a');
    cobj.Push('b');
    cobj.Push('c');
    cobj.Push('d');

    cobj.Display();

    char cRet = cobj.Pop();
    cout<<"1st Poped Element is :"<<cRet<<"\n";

    cRet = cobj.Pop();
    cout<<"2nd Poped Element is :"<<cRet<<"\n";

    iobj.Display();
    cout<<"------------------------------------------------------------------------------------------\n";

    Stack<double> dobj;
    
    dobj.Push(11.236);
    dobj.Push(21.258);
    dobj.Push(51.147);
    dobj.Push(101.897);

    dobj.Display();

    double dRet = dobj.Pop();
    cout<<"1st Poped Element is :"<<dRet<<"\n";

    dRet = dobj.Pop();
    cout<<"2nd Poped Element is :"<<dRet<<"\n";

    dobj.Display();
    return 0;
}