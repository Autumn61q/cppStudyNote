//在程序中定义函数digit(n,k),它能分离出整数n从右边数第k个数字
#include<iostream>
using namespace std;

int digit(int n,int k)
{
    if(k==1) return n%10;
    if(n==0) return 0;//注意这一行
    return digit(n/10,k-1);
}

int main()
{
    int n,k;
    cin>>n>>k;
    cout<<digit(n,k)<<endl;
    return 0;
}