//this pointer concept
//  each nonstatic mumber function will only produce one instance of the function,
//  that is,multiple objects of the same type will share a piece of code,so how 
//  does this piece of code distinguish between which object calls it?

//cpp provides this pointer to solve this problem.
//The this pointer points to the object to which the called member function belongs

//this pointer 是隐含在每一个非静态成员函数内的一种指针
//there is no need to define this pointer,just use it 

//the use of this pointer:
//  to distinguish form parameter and member variables when they have the same name
//      (however,one can use age and m_age to distinguish)
//  to return the object itself in the nonstatic member functions of a class,one can use return *this
//关于34行去掉&后的输出结果。。。。。
//指针也是变量，那么变量的话就是有值和有地址，指针的值就是所指向变量的地址，解引用就是把地址扒开拿到地址对应的那个值。
#include<iostream>
using namespace std;

class Person
{
public:
    int age;
    // Person(int age)
    // {
    //     age=age; //complier recognize the three age as the same thing,and the age outside constructor have nothing to do with them
    // }
    //one can write this:
    Person(){}
    Person(int age)
    {
        this->age=age;
    }
    Person& func() !!!!  //表示的是：返回值类型是Person&,因为Person* const p=&a;
    {
        this->age+=3;
        cout<<this->age<<endl;
        return *this;
    }

};
void test1()
{
    Person p(3);
    cout<<p.age<<endl;

}
void test2()
{
    Person p;
    //链式编程
    p.func().func().func();
    cout<<p.age<<endl;
}
int main()
{
    test2();
    return 0;
}