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
    Test operator++(int){ //post-increment
        Test back(a);
        a++;
        return back;
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