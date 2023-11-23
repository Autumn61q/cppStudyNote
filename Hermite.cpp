#include<iostream>
#include<iomanip>
using namespace std;

double Hermite(int n,int x)//注意如果想要用fixed和setprecision保留小数点后几位，前提一定是浮点数
{
    if(n==0) return 1;
    if(n==1) return 2*x;
    return 2*x*Hermite(n-1,x)-2*(n-1)*Hermite(n-2,x);
}
int main()
{
    int n,x;
    cin>>n>>x;
    cout<<fixed<<setprecision(2)<<Hermite(n,x)<<endl;
    return 0;
}