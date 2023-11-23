//输入一个以感叹号结尾的字符串，然后把它反过来。如：abc!->cba
#include<iostream>
#include<string>
using namespace std;

//这是我写的，它可以运行
// void reverse(string s,int i)
// {
//     if(s[i]=='!') return;
//     reverse(s,i+1);
//     cout<<s[i];
// }
void reverse2()
{
    char ch;
    cin>>ch;
    if(ch=='!') return;
    reverse2();
    cout<<ch;
}

int main()
{
    string user_input;
    cin>>user_input;
    reverse2();
    return 0;
}