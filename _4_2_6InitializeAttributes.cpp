//Initialize list
//effect:use the syntax to initialize list such that initialize member variables
//syntax:constructor():attribute1(value1),attribute2(value2),...{Realize}
#include<iostream>
using namespace std;

class Dog
{
    public:
    //traditional operation to initialize
    // Dog(int a,int b,int c)
    // {
    //     A=a;
    //     B=b;
    //     C=c;
    // }

    //initialize list to initialize attributes
    // Dog():A(10),B(20),C(30)
    // {

    // }

    //or you can write like this,for it is more flexible to initialize
    Dog(int a,int b,int c=8):A(a),B(b),C(c)
    {

    }
    int A;
    int B;
    int C;
};
int main()
{
    Dog Muyan(10,3);
    cout<<Muyan.A<<" "<<Muyan.B<<" "<<Muyan.C<<endl;
    return 0;
}
