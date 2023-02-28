//Accept number from user and display the maximum frequency of that number
#include<iostream>
using namespace std;
/*
Input : 7987677
Output : Maximum times occured digit is 7 and its frequency is 4
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

        void MaxFrequency()
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

            int iMaxFrequency = 0;
            int iMaxDigit = 0;
            for(int iCnt = 0; iCnt < 10; iCnt++)
            {
                if(Frequency[iCnt] > iMaxFrequency)
                {
                    iMaxFrequency = Frequency[iCnt];
                    iMaxDigit = iCnt;
                }
            }
            cout<<"Maximum times occured digit is "<<iMaxDigit<<"  and its frequency is "<<iMaxFrequency<<"\n";
        }
        
};

int main()
{
    int iValue = 0;
    int iRet = 0;

    cout<<"Enter number :"<<"\n";
    cin>>iValue;

    DigirX obj(iValue);

    obj.MaxsFrequency();
    
    return 0;
}