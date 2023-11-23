//the rules to call constructor
#include<iostream>
using namespace std;

//By default,the compiler of c++ will add at least 3 functions to a class
//1.default constructor(no parameter,empty bode)
//2.default destructor(no parameter,empty bode)
//3.default copy constructor (copy the value of member variables)

//the rules to call the constructors are as follows
//1).If a user defines a parameterized constructor,C++ will not provides a default parameterless constructor,but a default copy constructor 
//2).If a user defines a copy constructor,C++ will no longer provides examples of other constructors

class Person
{
 public:
    // Person(const Person &p)
    // {
    //     age=p.age;
    //     cout<<"this is the copy constructor"<<endl;
    // }
    Person(int a){
        age=a;
    }
    void getAge()
    {
        cout<<age<<endl;
    }
 private:
    int age;
};
int main(){
    Person p1(2);
    Person p2(p1);//compiler will defines a copy constructor which incorporates the code in line 19
    p2.getAge();
    return 0;
}