当类模板碰到继承时，需要注意以下几点：
  当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
  如果不指定，编译器无法给子类分配内存
  如果想灵活指出父类中T的类型，子类也要变成类的模板

template<class T>
class Base{
public:
    T m;
};

//1.
class Derived1:public Base<int>{};

//2.
template<class T2>
class Derived2:public Base<T2>{;
};

int main(){
    Derived1 d;
    return 0;
}
