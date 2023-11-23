#include<iostream>
using namespace std;

class Person{
    public:
    Person(){
        cout<<"person构造函数的调用"<<endl;//default constructor is used to initialize a new object
    }
    Person(int a){  //类中的函数后面可以加一个const,such as Person() const {};然后函数体内里面就不能进行第10行的操作了
        age=a;//actually this setAge function is called mutator function
        cout<<"person有参构造函数的调用"<<endl;
    }
    Person(const Person &p)
    {
        age=p.age;
        cout<<"person拷贝构造函数的调用"<<endl;
    }
    ~Person()
    {
        cout<<"Person的析构函数调用"<<endl;
    }
    int getAge(){
        return age;
    }
    private:
    int age;
};

int main(){
    //括号法调用
    Person p1;//call the default constructor
    Person p2(2);//call the parameterized constructor
    Person p3 (p2);//call the copy constructor
    //注意：在调用默认构造函数的时候不要加小括号
    //因为编译器会当成函数的声明（在一个函数内可以写另一个函数声明），就不会实例化
    Person p4();

    //显示法调用
    Person p5;
    Person p6=Person(p2);//右值是一个匿名对象，41行同理。
    Person p7=Person(10);
    //匿名对象特点：当前行结束后，系统会立刻回收匿名对象
    Person(10);
    cout<<"你可以看到43行的调用被析构之后才输出这句话，而其他的都是在函数执行完之后才析构的"<<endl;
    //注意：不要用一个拷贝构造函数来初始化匿名对象,编译器会认为Person (p3)==Person p3;就会和33行代码的p3重定义，报错
    //Person (p3);

    //隐式转换法调用
    Person p8=10;//相当于右值=Person(10)
    Person p9=p3;//copy the copy constructor
    return 0;

}