//when the base class and derived class have some members with same names...
    //access the subclass member with the same name: just access it
    //access the parent class member with the same name: add scope

#include<iostream>
using namespace std;
class Parent{
public:
    Parent(){sameName=100;}
    int sameName;
    void sleepy(){cout<<"Parent"<<endl;}
    void sleepy(int a){cout<<"Parent int a"<<endl;}
};

class Subclass:public Parent
{
public:
    Subclass(){sameName=1;}
    int sameName;
    void sleepy(){cout<<"Subclass"<<endl;}
};

int main(){
    Subclass s;
    cout<<s.sameName<<endl;
    cout<<s.Parent::sameName<<endl;
    s.sleepy();
    s.Parent::sleepy();
    //s.sleepy(100);报错，如果子类中出现了和父类中同名的成员函数，那么子类的成员函数会隐藏父类中所有同名的函数
    s.Parent::sleepy(100);
    return 0;
}