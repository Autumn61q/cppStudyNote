#include<iostream>
#include<string>
#include<sstream>
using namespace std;
 
int main(){
    int age;
    //standard input(cin)
    cout<<"Please enter an integer value as your age: ";
    cin>>age;
    cout<<"Your age is: "<<age<<".\n";
    //cin and string
    string mystr;
    cout<<"What's your name? "<<endl;
    getline(cin,mystr);
    cout<<"Hello,"<<mystr<<".\n";
    return 0;
}