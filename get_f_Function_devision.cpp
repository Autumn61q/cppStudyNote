//求f(x,n),分数那个
#include<iostream>
#include<iomanip>
using namespace std;

double f(int x,int n)
{
    if(n==0) return x;
    return x/(n+f(x,n-1));
}
int main()
{
    int x,n;
    cin>>x>>n;
    cout<<fixed<<setprecision(2)<<f(x,n)<<endl;
    return 0;
}