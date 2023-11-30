//纯虚函数和抽象类
    // 在多态中，通常父类中的虚函数的实现是无意义的，主要都是调用子类重定义的内容。因此可以将虚函数改为纯虚函数
    // 纯虚函数语法：virtual 返回值类型 函数名（参数列表）=0；
    // 当类中有了纯虚函数，这个类就称为抽象类

    // 抽象类特点：
    //     无法实例化对象
    //     子类必须重写(写一个空的实现也是重写)父类中的虚函数，否则也属于抽象类

// 记录一下接口和实现：
//     接口：接口是描述类提供的服务或功能的抽象描述。接口定义了类对外暴露
//         的方法、属性和行为，但不包含其具体实现。在C++中，接口通常通
//         过纯虚函数来实现，即在类中定义没有实际实现的虚函数。接口可以
//         被其他类继承或实现，从而实现接口描述的功能。
//     实现：实现是描述类具体功能和行为的部分。实现包括类的具体属性、方法
//         和行为的定义和实现。在C++中，实现通常通过类的定义和方法的实
//         现来实现。一个类可以实现一个或多个接口，从而提供接口描述的功能。
//     我的想法：老师说接口就是提供了一套规则，在这串代码里面，就是说
//             virtual void prepare()=0;是一个规则，它规定如果想要
//             prepare，就要把prepare实现了。又说，接口就是“如何做”，
//             实现就是“怎么做”
// 下面是案例：制作饮品
#include<iostream>
using namespace std;

class Drink{
public:
    virtual void prepare()=0;
};

class Tea:public Drink{
public:
    void prepare(){cout<<"making tea..."<<endl;}
};

class Coffee:public Drink{
public:
    void prepare(){cout<<"making tea..."<<endl;}
};

void doDrink(Drink &drink){
    drink.prepare();
    cout<<"enjoy it"<<endl;
}

int main(){
    Tea GreenTea;
    doDrink(GreenTea);
    return 0;
}
