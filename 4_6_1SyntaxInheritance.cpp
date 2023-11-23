//Inheritance: one of the three traits of OOP
    //use the techique of inheritance to reduce repeated code
    //(继承(inheritance)机制是面向对象程序设计中使代码可以复用的最重要的手段，
    //它允许程序员在保持原有类特性的基础上进行扩展，增加功能。这样产生的新类，称派生类（或子类），被继承的类称基类（或父类）。)
    //the Syntax of Inheritance: 
                            // class subclass(或者叫derived class): 继承方式 parent(或者是base class)

#include<iostream>
#include<string>
using namespace std;
class Info{
public:
    void school(){
        cout<<"zzyz"<<endl;
    }
    void num(){
        cout<<2315<<endl;
    }
};

class Qiuiue:public Info
{
public:
    void ID(){
        cout<<"666"<<endl;
    }
};

class JJ:public Info
{
public:
    void ID(){
        cout<<"888"<<endl;
    }
};

int main(){
    JJ jj;
    jj.ID();
    jj.school();
    jj.num();
    return 0;
}