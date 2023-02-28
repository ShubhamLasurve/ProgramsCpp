//Template for problems on digits
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
};

int main()
{
    int iValue = 0;

    cout<<"Enter number :"<<"\n";
    cin>>iValue;

    DigirX obj(iValue);

    cout<<obj.iNo<<"\n";

    return 0;
}