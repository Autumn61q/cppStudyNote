#include<iostream>
using namespace std;
//s(n)=s(n-1)+n
int sum(int n)
{
    if(n==0)//write the condition of termination first
    {
        return 0;
    }
    else return n+sum(n-1);
}
int main()
{
    cout<<sum(100)<<endl;
    return 0;
}