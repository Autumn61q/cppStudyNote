//求f(x,n)  连续开根号那个
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

double f(int x,int n)
{
    if(n==1) return sqrt(1+x);
    return sqrt(n+f(x,n-1));
}
int main()
{
    double x;
    int n;
    cin>>x>>n;
    cout<<fixed<<setprecision(2)<<f(x,n)<<endl;
    return 0;
}