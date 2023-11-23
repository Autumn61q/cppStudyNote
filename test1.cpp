#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream ifs;
    ifs.open("text.txt");
    char c=ifs.get();
    if('0'<=c&&c<='9') cout<<c;
    while(c=ifs.peek()){
        if('0'<=c&&c<='9') {c=ifs.get();cout<<c;}
    }
    c=ifs.get();
    if('0'<=c&&c<='9') cout<<c;
    return 0;
}