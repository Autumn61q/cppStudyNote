//class to be friend
#include<iostream>
using namespace std;
class Building{
    friend class jiajia;
public:
    string sittingroom;
    Building(){
        sittingroom=" ";
        bedroom="床";
    }
private:
    string bedroom;
};
class jiajia{
    public:
    jiajia(Building home){
        c=new Building(home);//在这里把c初始化，所以20行不需要把c赋值为nullptr
    }
    ~jiajia(){
        if(c!=nullptr){
            delete c;
            c=nullptr;
        }
    }
    Building *c;
    void showC(){
        c->sittingroom="看电视";
        c->bedroom="床床床";
        cout<<c->sittingroom<<endl;
        cout<<c->bedroom<<endl;
    }
};
int main(){
    Building home;
    jiajia Tongfang(home);
    //Tongfang.c->bedroom;//is wrong,can only access through functions
    Tongfang.showC();
    return 0;
}
