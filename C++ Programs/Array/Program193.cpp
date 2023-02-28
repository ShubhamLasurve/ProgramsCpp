#include<iostream>
using namespace std;

class DigirX
{
    public:
        int iNo;

        DigirX()
        {
            iNo = 0;
        }

        DigirX(int i)
        {
            iNo = i;
        }

        int SumEvenDigit()
        {
            int iSum = 0;
            int iDigit = 0;
            int iTemp = iNo;

            while(iTemp != 0)
            {
                iDigit = iTemp % 10;
                if((iDigit % 2) == 0)
                {
                    iSum = iSum + iDigit;
                }
               
                iTemp = iTemp /10;
            }
            return iSum;
        }
};

int main()
{
    int iValue = 0;
    int iRet = 0;

    cout<<"Enter number :"<<"\n";
    cin>>iValue;

    DigirX obj(iValue);

    iRet = obj.SumEvenDigit();

    cout<<"Summation of even digits : "<<iRet<<"\n";

    cout<<obj.iNo;      //Solution: Copy the value of iNo into temperory variable
    
    return 0;
}