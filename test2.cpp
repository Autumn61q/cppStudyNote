#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream inputFile("test.txt");//test.txt里面的内容可以是数字  字母  可以在不同字符中间带一些空格
    char ch;
    while((ch=inputFile.get())!=EOF){
        if ('0' <= ch && ch <= '9') {
            inputFile.unget(); /* oops - didn't want to read it */
            int n;
            inputFile >> n; /* read integer starting with ch */
            cout<<n;
        }
    }
    return 0;
}