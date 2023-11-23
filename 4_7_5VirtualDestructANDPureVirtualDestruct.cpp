虚析构和纯虚析构

    多态使用时，如果子类有属性开辟到堆区，那么父类指针在释放时无法调用子类的析构代码
                // #include<iostream>
                // using namespace std;

                // struct Base{
                //     int *barr;
                //     Base():barr(new int[10]) {};
                //     ~Base(){
                //         cout<<"Base destructor"<<endl;
                //         delete[] barr;
                //     }
                //     int c;
                // };

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
        解决方式：将父类中的析构函数改为虚析构或者纯虚析构

    虚析构和纯虚析构的共性：
        可以解决父类指针释放子类对象
        都需要有具体的函数实现
    虚析构和纯虚析构区别：
        如果是纯虚析构，该类属于抽象类，无法实例化对象

    虚析构的语法：virtual ~类名（）{}
    纯虚析构的语法： virtual ~类名（）=0