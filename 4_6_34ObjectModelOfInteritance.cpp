//4_6_3: object models in interitance

//4_6_4:the order of construct and destruct in Interitance
    //when derived class is creating a object, the constructor of Base class will be called
#include<iostream>
using namespace std;

class Base{
public:
    Base(){cout<<"Base constructor"<<endl;}
    ~Base(){cout<<"Base destructor"<<endl;}
    int a;
protected:
    int b;
private:
    int c;
};
class Derive:public Base
{
public:
    Derive(){cout<<"Derive constructor"<<endl;}
    ~Derive(){cout<<"Derive destructor"<<endl;}
};
int main(){
    cout<<sizeof(Base)<<endl;//print 12
    cout<<sizeof(Derive)<<endl;//print 12:进一步说明父类中的private是被子类继承了的;also,其他的父类成员，也被子类继承了
    Derive test;//先有爸爸再有儿子
    return 0;
}



