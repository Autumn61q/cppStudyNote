类模板对象做函数参数
三种传参方式：第一种最常用
  1.指定传入类型：直接显示对象的数据类型
  2.参数模板化：将对象中的参数变为模板进行传递
  3.整个类模板化：将这个对象类型模板化进行传递

template<class T>
class Person{
public:
    T age;
};

//1.
void foo1(Person<int> &p){}

//2.foo2也是一个模板函数了
template<class T1>
void foo2(Person<T1> &p){
    //typeid(T1).name()就是可以查看T1的数据类型。使用typeid要包含头文件typeinfo
    cout<<typeid(T1).name()<<endl;//输出i，是int的缩写
    }

//3.
template<class T2>
void foo3(T2 &p){}

int main(){
    Person<int> p;
    cout<<typeid(p).name()<<endl;//输出6PersonIiE
    // 6：表示类型名称的长度（不包括结尾的空字符）。
    // Person：表示类型名称的基本部分，即模板类 Person 的名称。
    // I：表示模板参数开始的标记。
    // i：表示具体的模板参数类型，这里是 int。
    // E:标志着类型名称的结束
    p.age=3;
    foo1(p);
    foo2(p);
    foo3(p);
    return 0;
}
