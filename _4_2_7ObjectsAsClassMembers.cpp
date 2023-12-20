//class objects as class members
//in C++,the objects of one class can be members in another class,and this kind of member is called object member

#include<iostream>
using namespace std;

class A
{
    public:
    A()
    {
        cout<<"A constructor"<<endl;
    }
    ~A()
    {
        cout<<"A destructor"<<endl;
    }
};

class B
{
    public:
    A a;
    B()
    {
        cout<<"B constructor"<<endl;
    }
    ~B()
    {
        cout<<"B destructor"<<endl;
    }
};

int main()
{
    B b;//栈：先进后出。我还看到一个很棒的观点：先构造出零件，再用零件拼成自身
    return 0;
}


