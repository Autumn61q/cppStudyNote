#include<iostream>
using namespace std;

//the timing to call the copy constructor：
// 1.使用一个已经创建完毕的对象来初始化一个新对象
// 2.值传递的方式给参数传值
// 3.以值方式返回局部对象（但是现在在很多编译器中，gcc做了优化，返回值为类对象的时候不再调用拷贝构造）
class Person{
    public:
    Person()
    {
        cout<<"this is the default constructor"<<endl;
    }
    ~Person()
    {
        cout<<"this is the default destructor"<<endl;
    }
    Person(int age)
    {
        m_age=age;
        cout<<"this is the parameterized destructor"<<endl;
    }
    Person(const Person &p)
    {
        m_age=p.m_age;
        cout<<"this is the copy destructor"<<endl;
    }
    private:
    int m_age;
};
//1.
void test01()
{
    Person p1(2);
    Person p2(p1);
}
//2.
void test03(Person p);
void test02()
{
    Person p;
    test03(p);
}
void test03(Person p)
{

}
//3.
Person test04()
{
    Person p;
    return p;//用值方式返回
}
void test05(){
    Person p=test04();
}

int main(){
    // test01();
    //test02();
    test05();
    return 0;
}