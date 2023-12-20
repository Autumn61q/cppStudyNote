//operator overloading
    //redefine the exist operator to give it new function to adapt different types of date
    //注：内置数据类型的表达式的运算符是不可更改的；不要滥用运算符重载

//plus sign overloading: to achieve the operation of adding two user-defined date types 
#include<iostream>
using namespace std;

//第一种：用成员函数重定义
class Test{
public:
    int A;
    int B;
    Test();
    Test operator+(Test &p);
};

Test::Test():A(10),B(5){}

Test Test::operator+(Test &p){
    Test result;
    result.A+=p.A;
    result.B+=p.B;
    return result;
}

Test operator+(Test &a,int b);

int main(){
    Test t1,t2;
    //本质：Test t3=t1.operator+(t2);
    Test t3=t1+t2;
    cout<<t3.A<<endl; // print 15
    t1.A=9;
    cout<<t3.A<<endl; // print 15
    return 0;
}


//第二种：用全局函数重定义
// class Test{
// public:
//     int A;
//     int B;
//     Test();
// };

// Test::Test():A(10),B(5){}

// Test operator+(Test &a,Test &b){
//     Test result;
//     result.A=a.A+b.A;
//     result.B=a.B+b.B;
//     return result;
// }

// int main(){
//     Test t1,t2;
//本质：Test t3=operator+(t1,t2);
//     Test t3=t1+t2;
//     cout<<t3.A<<endl;
//     t1.A=9;
//     cout<<t3.A<<endl;
//     return 0;
// }


//运算符重载，也可以发生函数重载
//如：（接第一种情况）

Test operator+(Test &a,int b){ //operator overloading can not use default parameters.you can use the function below
    Test result;
    result.A=a.A+b;
    return result;
}

// Test operator+(Test &a){
//     Test result=add(a,10);// call a function which has default parameter
// }
