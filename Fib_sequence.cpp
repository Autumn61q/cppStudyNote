#include<iostream>
using namespace std;
//F(0)=0  F(1)=1
//F(n)=F(n-1)+F(n-2)
int Fib(int n)
{
    if(n==0) return 0;
    else if(n==1) return 1;
    else
    return Fib(n-1)+Fib(n-2);
}
int main()
{
    cout<<Fib(5)<<endl;
    return 0;
}