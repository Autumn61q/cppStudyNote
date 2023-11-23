// Function call operator() overloading
    //the way it used after overloading is very much like a function,thus it is called a functor(仿函数)
    //functors have no fixed way of writing and are very flexible

#include<iostream>
using namespace std;
class Oper{
public:
    void operator()(string m){
        cout<<m<<endl;
    }
    int operator()(int a,int b){
        return a+b;
    }
};
int main(){
    Oper add;
    cout<<add(3,5)<<endl;
    Oper print;
    print("仿函数真的很离谱");
    //anonymous function object
    cout<<Oper()(5,6)<<endl;
    return 0;
}