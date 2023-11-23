// the basic concept of polymorphism
//多态是面向对象的三大特性之一
    // 多态分为两类：
    //     静态多态：函数重载和运算符重载属于静态多态，复用函数名
    //     动态多态：派生类和虚函数（virtual function）实现运行时多态

    // 静态多态和动态多态的区别:
    //     静态多态的函数地址早绑定（编译阶段确定函数地址）
                // 静态多态性是基于参数类型和数量进行绑定的，而不是基于实际运行时对象的类型。
                // 这意味着在静态多态性中，编译器在编译时就确定了要调用的函数，而不是在运行时
                // 根据实际对象的类型来确定调用哪个函数。(但是该继承还得继承)
    //     动态多态的函数地址晚绑定（运行阶段确定函数地址）

    // 多态的好处：1、组织结构清晰  2、可读性强  3、便于后续维护和开发（开发的话只用追加，不会在源代码里面修修改改）

// #include<iostream>
// using namespace std;
// class Animal{
// public:
//     void speak(){cout<<"动物在叫唤"<<endl;}
// };
// class Cat:public Animal{
// public:
//     void speak(){cout<<"喵喵喵"<<endl;}
//     int a;
// };
// void doSpeak(Animal &dongwu){
//     dongwu.speak();//这个输出结果说明doSpeak的地址早绑定，早就已经确定执行的是Animal下的speak
//     //cout<<dongwu.a<<endl;

// }
// int main(){
//     Cat Sabrina;
//     //派生类对象可以在函数调用的时候转化为基类对象传入到21行的参数列表中；
//     //转化之后派生类对象相对于基类对象特有的东西都会消失(line 24 error)
//     //但是基类对象不能转化成派生类对象，因为基类对象不一定有派生类对象的行为和属性
//     doSpeak(Sabrina);
//     return 0;
// }

//如果想要调用Cat里面的那个Speak就用虚函数
//动态多态满足条件：1.有继承关系 2.子类重写（或者叫重定义）(返回值（返回值如果不同会报错） 函数名 形参列表都要相同,如果有一个不同，就会按照调用的具体情况来区分调用的函数）父类的虚函数
// #include<iostream>
// using namespace std;
// class Animal{
// public:
//     virtual void speak(){cout<<"动物在叫唤"<<endl;}
// };
// class Cat:public Animal{
// public:
//     void speak(){cout<<"喵喵喵"<<endl;}
//     int a;
// };
// void doSpeak(Animal &dongwu){
//     dongwu.speak();
//     // cout<<dongwu.a<<endl; 还是报错
// }
// int main(){
//     Cat Sabrina;
//     doSpeak(Sabrina);
//     return 0;
// }

#include<iostream>
using namespace std;
class Animal{
public:
    virtual void speak(){cout<<"动物在叫唤"<<endl;}
};
class Cat:public Animal{
public:
    void speak(){cout<<"喵喵喵"<<endl;}
    int a;
};
void doSpeak(Animal &dongwu){
    dongwu.speak();
}
int main(){
    Cat Sabrina;
    doSpeak(Sabrina);
    cout<<sizeof(Animal)<<endl;//print 8(说明存了一个指针)
    return 0;
}

// Animal 内部存了一个虚函数指针（或者叫虚函数表指针）(vfptr),它会指向Animal的一个虚函数表(vftable),这个表里面记录了Animal里面所有的虚函数地址
// Cat继承Animal的时候，连表带指针一起继承过来。但是当子类重写父类的虚函数的时候，被重写的那个Animal::speak就会被Cat::speak覆盖。虚函数指针会根
// 据对象的实际类型指向相应的虚函数表，从而实现多态。当用Cat类型的Sabrina调用73行的函数的时候，会发生Animal &dongwu=Sabrina的隐式转化,


//例：这个例子是说，对于非虚函数ViewAcct，程序将根据引用或指针的类型选择方法
// // behavior with non-virtual ViewAcct()
// // method chosen according to reference type
// Brass dom("Dominic Banker", 11224, 4183.45);
// BrassPlus dot("Dorothy Banker", 12118, 2592.00);
// Brass & b1_ref = dom;
// Brass & b2_ref = dot;
// b1_ref.ViewAcct(); // use Brass::ViewAcct()
// b2_ref.ViewAcct(); // use Brass::ViewAcct()


// In contrast, here is the behavior if ViewAcct() is virtual:
// // behavior with virtual ViewAcct()
// // method chosen according to object type
// Brass dom("Dominic Banker", 11224, 4183.45);
// BrassPlus dot("Dorothy Banker", 12118, 2592.00);
// Brass & b1_ref = dom;
// Brass & b2_ref = dot;
// b1_ref.ViewAcct(); // use Brass::ViewAcct()
// b2_ref.ViewAcct(); // use BrassPlus::ViewAcct()

