//static member:
//              add "static" before the attributes and member functions to create static members
//              there also access right for static member(the private can not be accessed out-of-class)

//classification:

//1.static member variables:
//:all the objects share the same data
//: allocate memory(global area) at the compile stage
//in-class declaration and out-of-class initialization

//2.static member functions
//:all the objects share the same function
//:static member functions can only access static member variables

#include<iostream>
using namespace std;

class Person
{
    public:
    static int A;
};
int Person::A=100;//no need to write "static";"Person::" declare the scope
void test1()
{
    Person p;
    Person p2;
    p2.A=10;
    cout<<p.A<<endl;//prints out 10
}
void test2()
{
    //static members does not belong to any objects,for all objects share the same memory
    //Thus there are two methods to access it

    //1.through objects(like test1)

    //2.through the name of the class
    cout<<Person::A<<endl;
}
int main()
{
    test2();
    Person::A=50;
    cout<<Person::A<<endl;
    return 0;
}