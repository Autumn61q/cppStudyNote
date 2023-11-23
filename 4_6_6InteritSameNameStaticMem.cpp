// things about same name static member in Interitance
    //just like the same name non-static member 函数和成员都同理

#include<iostream>
using namespace std;

class Mum{
public:
    static int sameName;
};

class Son:public Mum{
public:
    static int sameName;
};

int Mum::sameName=1;
int Son::sameName=2;

int main(){
    Son t;
    //access through object
    cout<<t.sameName<<endl;
    cout<<t.Mum::sameName<<endl;
    //access through the name of class
    cout<<Son::sameName<<endl;
    cout<<Mum::sameName<<endl;
    return 0;
}
