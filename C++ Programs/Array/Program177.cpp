// Problems on number Template
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

        void Function()//Here you want to place the function with business logic
        {
            //Logic
        }
};

int main()
{
    int iValue = 0;

    cout<<"Enter the number : \n";
    cin>>iValue;

    Numbers obj(iValue);

    obj.Function();
    
    return 0;
}