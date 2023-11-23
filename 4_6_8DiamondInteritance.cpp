//菱形继承的概念：
    //两个派生类继承同一个基类，又有某一个类继承两个派生类(就会导致“某一个类”继承了分别从两个派生类继承了两次基类，可能导致二义性)

// #include<iostream>
// using namespace std;

// class Base{
// public:
//     int a;
// };
// class Derive1: public Base{};
// class Derive2: public Base{};
// class Dederive:public Derive1,public Derive2{};
// int main(){
//     Dederive test;
//     test.Derive1::a=1;
//     test.Derive2::a=2;
//     //但是实际上在test只需要一个a，现在有两个，导致资源浪费。
//     return 0;
// }

//利用虚继承可解决菱形继承的问题
    //虚基类子对象是指从虚基类派生出来的子对象(在面向对象编程中，子对象是指一个类中
    // 包含的其他类的对象。当一个类通过继承或组合关系与其他类相关联时，这些其他类的对象
    // 就可以被称为该类的子对象。)，在派生类中作为基类的一部分存在。当一个类被声明为虚
    // 基类时，它的派生类将会共享该虚基类的成员，并且在派生类的对象中只会有一个虚基类子
    // 对象。
    // 为了能够正确访问这些虚基类的成员，编译器会在派生类对象中添加一个指向虚基类子对
    // 象的指针，这个指针被称为虚基类指针(vbptr)。vbptr指向虚基类表（vbtable),如
    // Derive1的vbptr指向Derive1的虚基类表，指针通过偏移量找到虚基类子对象虚基类指针
    // 的偏移量是指该指针相对于派生类对象起始地址的偏移量（虚基类指针的偏移量在每个派
    // 生类对象中是不同的）。
#include<iostream>
using namespace std;

class Base{//称为虚基类
public:
    int a;
};
class Derive1: virtual public Base{};
class Derive2: virtual public Base{};
class Dederive:public Derive1,public Derive2{};
int main(){
    Dederive test;
    test.Derive1::a=1;
    test.Derive2::a=2;
    cout<<test.Derive1::a<<" "<<test.Derive2::a<<endl; //print 2 2
    cout<<test.a<<endl;
    cout<<sizeof(Derive1)<<endl;
    return 0;
}