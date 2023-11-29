// 虚析构和纯虚析构

//     多态使用时，如果子类有属性开辟到堆区，那么父类指针在释放时无法调用子类的析构代码
                #include<iostream>
                using namespace std;

                struct Base{
                    int *barr;
                    Base():barr(new int[10]) {};
                    ~Base(){
                        cout<<"Base destructor"<<endl;
                        delete[] barr;
                    }
                    int c;
                };

                struct Derived:Base{
                    int *darr;
                    int a;
                    Derived():darr(new int[10]){}
                    ~Derived(){
                        cout<<"Derived destructor"<<endl;
                        delete[] darr;
                    }
                };

                void some_function(Base *b){
                    delete b;
                    // 当使用基类指针指向派生类对象时，如果基类的析构函数不是虚函数，
                    // 那么在使用基类指针进行delete操作时，只会调用基类的析构函数，
                    // 而不会调用派生类的析构函数。这是因为在编译时，编译器只知道b是
                    // 一个Base指针，无法确定它所指向的实际对象的类型。
                }

                int main(){
                    Derived *d=new Derived;
                    some_function(d);
                    return 0;
                }
    //     解决方式：将父类中的析构函数改为虚析构或者纯虚析构

    // 虚析构和纯虚析构的共性：
    //     可以解决父类指针释放子类对象
    //     都需要有具体的函数实现
    // 虚析构和纯虚析构区别：
    //     如果是纯虚析构，该类属于抽象类，无法实例化对象

    // 虚析构的语法：virtual ~类名（）{}
    // 纯虚析构的语法： virtual ~类名（）=0
    // 总结：虚析构和纯虚析构都是为了解决子类有属性开辟到堆区,
    // 且父类指针指向子类对象（你把27行的参数类型改为Derived
    // 就不会有这个问题）时，子类的析构函数调不到的问题

// #include<iostream>
// using namespace std;

// struct Base{
//     int *barr;
//     Base():barr(new int[10]) {};

//     // 像这样改成纯虚析构,但是你不能只写58行。必须要有具体的实现。因为假设父类中有属性开辟到堆，还要手动释放呢。所以我们加上62行
//     virtual ~Base()=0;
//     // // 像这样改成虚析构
//     // virtual ~Base(){
//     //     cout<<"Base destructor"<<endl;
//     //     delete[] barr;
//     // }
//     int c;
// };

// Base::~Base(){
//   cout<<"Pure Base Destructor"<<endl;
// }

// struct Derived:Base{
//     int *darr;
//     int a;
//     Derived():darr(new int[10]){}
//     ~Derived(){
//         cout<<"Derived destructor"<<endl;
//         delete[] darr;
//     }
// };

// void some_function(Base *b){
//     delete b;
//     // 当使用基类指针指向派生类对象时，如果基类的析构函数不是虚函数，
//     // 那么在使用基类指针进行delete操作时，只会调用基类的析构函数，
//     // 而不会调用派生类的析构函数。这是因为在编译时，编译器只知道b是
//     // 一个Base指针，无法确定它所指向的实际对象的类型。
// }

// int main(){
//     Derived *d=new Derived;
//     some_function(d);
//     return 0;
// }
