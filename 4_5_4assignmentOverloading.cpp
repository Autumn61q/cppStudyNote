//assignment operator overloading
#include<iostream>
using namespace std;

class Test{
public:
    int *m_a;
    Test(int a){
       m_a=new int(a); 
    }
    Test (Test& p){
        m_a=new int(*p.m_a);
    }
    ~Test(){
        if(m_a!=nullptr){
            delete m_a;
            m_a=nullptr;
        }
    }
    Test& operator=(Test &p){
        //应该先判断是否有属性在heap area(就是m_a有没有值)，如果有先释放
        if(m_a!=nullptr){
            delete m_a;//当使用 delete 运算符释放指针动态分配的内存后，指针所在的内存并没有被释放。
            m_a=nullptr;
        }
        //deep copy
        m_a=new int(*p.m_a);
        //对于内置数据类型，可以进行如下操作，为了使重定义的数据类型有相同的效果，咱要有一个返回值
        // int a=1,b=2,c=3;
        // a=b=c;
        // cout<<a<<" "<<b<<" "<<c<<endl;  //print： 3 3 3
        return *this;
    }
};
int main(){
    Test t1(18);
    Test t2(10);
    t1=t2;//只有拷贝构造函数是不能比较好的执行这一步的。拷贝构造函数只在对象创建时调用，而赋值运算符重载在对象已经存在时调用，因此需要定义赋值运算符重载来确保正确的行为。
    //下面三行代码输出什么取决于编译器
    // cout<<*t1.m_a<<endl;
    // t2=18;
    // cout<<*t1.m_a<<endl;
    return 0;
}