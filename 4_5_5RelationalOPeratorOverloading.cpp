//relational operator(> < == !=) overloading
#include<iostream>
using namespace std;
class Test{
private:
    int m_a;
public:
    Test(int a): m_a(a){};
    bool operator==(Test &p){
        if(m_a==p.m_a) return true;
        return false;
    }
    bool operator!=(Test &p){
        if(m_a!=p.m_a) return true;
        return false;
    }
    bool operator<(Test &p){
        if(m_a<p.m_a) return true;
        return false;
    }
    bool operator>(Test &p){
        if(m_a>p.m_a) return true;
        return false;
    }
};
int main(){
    Test t1(1);
    Test t2(2);
    cout<<(t1==t2)<<endl;
    return 0;
}