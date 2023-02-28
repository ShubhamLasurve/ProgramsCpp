//Accept number from user and display the frequency of that number
#include<iostream>
using namespace std;
/*
Input : 7985674
Output : 4 occurs 1 times
         5 Occurs 1 times
         6 Occurs 1 times
         7 Occurs 2 times
         8 Occurs 1 times
         9 Occurs 1 times
*/
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

        void DisplayFrequency()
        {
            int iTemp = iNo;
            int iDigit = 0;
            int Frequency[10] = {0};

            while(iTemp != 0)
            {
                iDigit = iTemp % 10;
                Frequency[iDigit]++;

                iTemp = iTemp / 10;
            }

            for(int iCnt = 0; iCnt < 10; iCnt++)
            {
                if(Frequency[iCnt] > 0)
                {
                    cout<<iCnt<<" occurs at"<<Frequency[iCnt]<<" times"<<"\n";
                }
            }

        }
        
};

int main()
{
    int iValue = 0;
    int iRet = 0;

    cout<<"Enter number :"<<"\n";
    cin>>iValue;

    DigirX obj(iValue);

    obj.DisplayFrequency();
    
    return 0;
}