//global functions to be friend
    //we can use friend technique to let the functions or classes out-of a specific class access or even modify the private properties

    //three kinds of inplementations of friend:
        //global functions to be friend
        //class to be friend
        //member functions to be friend

#include<iostream>
using namespace std;

class Building{
    friend void jiaojiao(Building &b);
public:
    string sittingroom;
    Building(){
        sittingroom=" ";
        bedroom="床";
    }
private:
    string bedroom;
};

void jiaojiao(Building &home){
    home.bedroom="桌子";
    cout<<home.bedroom<<endl;
}
//but you can not write like this :cannot create a object and then access the private attributes in friend, you can only access
// void jiaojiao(){
//     Building home;
//     cout<<home.bedroom<<endl; // of course, you can also change the value of bedroom
// }
int main(){
    Building q;
    jiaojiao(q);
    return 0;
}
