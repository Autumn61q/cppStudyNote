//increment operator overloading
#include<iostream>
using namespace std;
class Test{
    friend ostream& operator<<(ostream& cout,Test&p);
public:
    Test(int a):a(a){};
    Test& operator++(){ //pre-incrementation
    a++;
    return *this;
}
    Test operator++(int){ //post-increment  //int is to distinguish prefix and suffix to avoid re-define a function,除此之外int没有别的意义，只是约定俗成写个int罢了
        //firstly,record the object before increment
        Test back(a);
        //then do the incrementation
        a++;
        //return the record
        return back;//don't return reference of a local object
    }
private:
    int a;
};
ostream& operator<<(ostream& cout,Test&p){
    cout<<p.a;
    return cout;
}
int main(){
    Test p(5);
    cout<<p++<<endl;
    return 0;
}