//member functions to be friend
#include<iostream>
using namespace std;
//发现了，友元函数所在类要写在最前面，然后在友元函数前面加上其想要访问的类的声明
class Building;

class QQ{
    public:
    Building* p;
    QQ();
    ~QQ();
    void visit();
};

class Building{
    friend void QQ::visit();
public:
    string sittingroom;
    Building();
private:
    string bedroom;
};

Building::Building(){
    sittingroom=" ";
    bedroom="床";
}


QQ::QQ(){
    p=new Building;
}

QQ::~QQ(){
    if(p!=nullptr){
        delete p;
        p=nullptr;
    }
}

void QQ::visit(){
    cout<<p->bedroom<<endl;
}

int main(){
    QQ qiu;
    qiu.visit();
    return 0;
}