//Program to find smallest number
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

class MarvellousLB : public ArrayX
{
    public:
        MarvellousLB(int i) : ArrayX(i)     //Base member initilization or explicit constructor call
        { }
         
        int minimum()
        {
            int iMin = Arr[0];
            for(int iCnt = 0;iCnt < iSize; iCnt++)
            {
                if(Arr[iCnt] < iMin)
                {
                    iMin = Arr[iCnt];
                }
            }
            return iMin;
        }
};

int main()
{
    int iLength = 0;
    int iRet = 0;

    cout<<"Enter the elements \n";
    cin>>iLength;

    MarvellousLB * obj = new MarvellousLB(iLength);

    obj->Accept();
    obj->Display();

    iRet = obj->minimum();

    cout<<"Smallest element is :"<<iRet<<"\n";

    delete obj; 
    
    return 0;
}