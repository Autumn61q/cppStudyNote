#include<iostream>
#include<string>
using namespace std;

template<class T1,class T2>//写在showPerson2的上方，让showPerson2知道
class Person;

template<class T1,class T2>// 写在类的定义的上方，让类知道
void showPerson2(Person<T1,T2> p){
        cout<<"name:"<<p.name<<"  age:"<<p.age<<endl;
}

template<class T1,class T2>
class Person
{
    //全局函数类内实现(recommended, because it is easier)
    friend void showPerson1(Person<T1,T2> p){
        cout<<"name:"<<p.name<<"  age:"<<p.age<<endl;
    }

    //全局函数类外实现
    friend void showPerson2<>(Person<T1,T2> p);//加一个那个空的<>

public:
    Person(T1 name,T2 age):name(name),age(age){}
private:
    T1 name;
    T2 age;
};

int main(){
    Person<string,int> p("Tom",19);
    showPerson1(p);
    return 0;
}
