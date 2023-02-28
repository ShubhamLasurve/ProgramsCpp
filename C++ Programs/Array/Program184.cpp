#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;      //int  *Arr
        int iSize;

        ArrayX(int i)
        {
            cout<<"Allocating the memory for resources..."<<"\n";
            iSize = i;
            Arr = new int[iSize];      //Arr = (int *)malloc(iSize * sizeof(int));
        }

        ~ArrayX()
        {
            cout<<"Memory deallocated successfully\n";
            delete[]Arr;        //free(Arr);
        }

        void Accept()
        {
            cout<<"ENter the elements of array :"<<"\n";

            for(int iCnt = 0;iCnt < iSize; iCnt++)
            {
                cin>>Arr[iCnt];        //scanf("%d",&Arr[i]);
            }
        }

        void Display()
        {
            cout<<"Elements of array are :"<<"\n";

            for(int iCnt = 0; iCnt < iSize; iCnt++)
            {
                cout<<Arr[iCnt]<<"\t";        //printf("%d",Arr[iCnt]);
            }
            cout<<"\n";
        }
};

int main()
{
    int iLength = 0;

    cout<<"Enter the elements \n";
    cin>>iLength;

    ArrayX obj(iLength);        //Static

    obj.Accept();
    obj.Display();

    return 0;
}