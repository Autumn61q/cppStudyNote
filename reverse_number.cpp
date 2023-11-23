//倒序数
#include<iostream>
using namespace std;
void f(int x)
{
    if(x==0) return;
    cout<<x%10;//得到个位
    f(x/10);//去掉个位
}
int main()
{
    int x;
    cin>>x;
    f(x);
    return 0;
}