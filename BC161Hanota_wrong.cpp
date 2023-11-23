#include<iostream>
using namespace std;
int move(int num,char a='a',char b='b',char c='c'){
    static int count=0;
    if(num==0) return count;
    count+=move(num-1,a,b,c);
    count++;
    count+=move(num-1,c,b,a);
    count++;
    count+=move(num-1,a,b,c);
    return count;
}

int main()
{
    int n;
    while(cin>>n){
        cout<<move(n)<<endl;
    }
    return 0;
}