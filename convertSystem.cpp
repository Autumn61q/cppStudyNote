#include<iostream>
#include<vector>
using namespace std;
void convert(int n,int M)
{
    if(n==0) return;
    int r=n%M;
    convert(n/M,M);
    if (r<10) cout<<r;
    else
    {
        cout<<(char)(r+55);
    }
}
int main()
{
    vector<char> result;
    convert(78,16);
    return 0;
}