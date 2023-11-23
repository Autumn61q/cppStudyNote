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
//:static member functions can only access static member variables(otherwise there is error)
//                                                                (for the function does not know the local member variable in which object will be accessed)

#include<iostream>
using namespace std;

class Person
{
    public:
    static int A;
    int B;
    static void func(int a)
    {
        A=a;
        cout<<A<<endl;
        cout<<"call static void function"<<endl;
    }
};

int Person::A;

void test1()
{
    //1.call the static member function by objects
    Person p;
    p.func(5);
}

void test2()
{
    //2.call through the name of the class
    Person::func(5);
}
int main()
{
    test2();
    return 0;
}