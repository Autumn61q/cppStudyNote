//const modifies member functions
    //constant functions:
        //we call a member function a constant function when we add const to it
        //member attributes cannot be changed inside a constant function
        //member property with "mutable" can be changed inside a constant function
    //constant object:
        //add const before declare a object to create a constant object
        //constant object can only call constant functions

#include<iostream>
using namespace std;

class Person{
    public:
    string name="";
    mutable int age=0;
    void no_use() const{
        //this point inside this function is: const Person* const this;
        cout<<name<<endl;
        // name="99";
        age=9;
        cout<<age<<endl;
    }
    void no_use2(){};

};

int main(){
    Person test1;
    Person* p=&test1;
    test1.name="hh";
    p->no_use();
    //cteate a constant object
    const Person test2;
    test2.no_use(); 
    // test2.no_use2();
    return 0;
}