//Factorial
#include<iostream>
using namespace std;

class Numbers
{
    public:
        int iNo;

        Numbers(int i)
        {
            iNo = i;
        }

        int Factorial()
        {
            int iFact = 1;
            int iCnt = 0;
            for(iCnt = 1;iCnt <= iNo;iCnt++)
            {
                iFact = iFact * iCnt;
            }
            return iFact;
        }
};

int main()
{
    int iValue = 0;
    int iRet= 0;

    cout<<"Enter the number : \n";
    cin>>iValue;

    Numbers obj(iValue);

    iRet = obj.Factorial();

    cout<<"Factorial of givn number is :"<<iRet<<"\n";
    
    return 0;
}