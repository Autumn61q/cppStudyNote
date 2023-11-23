//c++ object models and this pointers

    //member variables and member functions store separately
        //in c++,the member variables and member functions in objects are stored separately
        //only non-static member variables belong to the objects of class

        
#include<iostream>
using namespace std;

class Person1   //null objects occupy 1 byte
{

};
class Person2   //occupy 4 bytes->就是A的内存大小，shows that the nonstatic members belong to the object of class
{
    int A;
};
class Person3
{
    static int A;
};
int Person3:: A=0;
class Person4
{
    void func(){};//非静态成员函数不属于类的对象
};
void test1()
{
    Person1 p1;
    cout<<sizeof(p1)<<endl;//print 1
    Person2 p;
    cout<<sizeof(p)<<endl;  //print 4
    Person3 p2;
    cout<<sizeof(p2)<<endl; //print 1
    Person4 p3;
    cout<<sizeof(p3)<<endl;//print 1
}
int main()
{
    test1();
    return 0;
}