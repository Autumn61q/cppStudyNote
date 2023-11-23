//null pointer access the member functions
    //null pointer can call member functions in c++,but to notice while we use this pointer
    //if so,we need to apply judgement to increase the robustness of the code
#include<iostream>
using namespace std;

class Person{
public:
void showClassName(){
    cout<<"This is Person class"<<endl;
}
int showAge(){
    if(this==NULL) return 0;
    //actually the code below is return this->m_age;
    return m_age;
}
private:
int m_age=0;
};
void test01(){
    Person* p;
    // p->showAge();the code will crash because this point in line15 doesn't know the object ,thus we can add line13
    p->showClassName();//the program will not crash
}
int main(){
    test01();
    return 0;
}