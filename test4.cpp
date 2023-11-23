#include<iostream>
using namespace std;

class Base{
public:
    int a;
};
class Derive1: public Base{};
class Derive2: public Base{};
class Dederive:public Derive1,public Derive2{};
int main(){
    Dederive test;
    test.Derive1::a=1;
    test.Derive2::a=2;
    //但是实际上在test只需要一个a，现在有两个，导致资源浪费。
	cout<<test.Derive1::a<<endl;
    return 0;
}