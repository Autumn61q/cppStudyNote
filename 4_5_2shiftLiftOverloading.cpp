//shift lift operator overloading
//一般不会利用成员函数实现重载，因为写出来是 p.operator<<(cout) 简化为 p<<cout,与通常习惯不符
#include<iostream>
using namespace std;

class Test{
    friend ostream& operator<<(ostream& cout,Test &p);
public:
    Test():a(10),b(5){}; //可不敢把构造函数设成private,不然实例化都不一定行
private:
    int a;
    int b;
};
// void operator<<(ostream &cout,Test &p){  //cout在全局只能有一个，所以用引用传进来
//     cout<<"a:"<<p.a<<"  b:"<<p.b;
// }
// int main(){
//     Test p;
//     cout<<p;//在这个后面不能加<<endl;因为链式编程思想，if so，cout<<p需要有返回值
//     return 0;
// }
ostream& operator<<(ostream &cout,Test &p){  //cout在全局只能有一个，所以用引用传进来,引用传出去
    cout<<"a:"<<p.a<<"  b:"<<p.b;
    return cout;
}

int main(){
    Test p;
    cout<<p<<endl;
    return 0;
}