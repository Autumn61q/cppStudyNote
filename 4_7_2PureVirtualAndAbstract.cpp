//纯虚函数和抽象类
    // 在多态中，通常父类中的虚函数的实现是无意义的，主要都是调用子类重定义的内容。因此可以将虚函数改为纯虚函数
    // 纯虚函数语法：virtual 返回值类型 函数名（参数列表）=0；
    // 当类中有了纯虚函数，这个类就称为抽象类

    // 抽象类特点：
    //     无法实例化对象
    //     子类必须重写(写一个空的实现也是重写)父类中的虚函数，否则也属于抽象类

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