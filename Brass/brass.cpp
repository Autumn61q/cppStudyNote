#include<iostream>
#include"brass.h"
using std::cout;
using std::endl;
using std::string;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f,precis p);//上面几行是啥东西

Brass::Brass(const string &s,long an,double bal){//默认参数可以在函数声明和定义中指定，但是一般建议在函数声明中指定默认参数，而不是在函数定义中指定。如果在函数声明和定义中都指定了默认参数，那么函数定义中指定的默认参数将覆盖函数声明中指定的默认参数。
    fullName=s;
    acctNum=an;
    balance=bal;
}

void Brass::Deposit(double amt){
    if(amt<0) cout<<"Negative deposit not allowed;"<<"deposit is cancelled.\n";
    else balance+=amt;
}
void Brass::Withdraw(double amt){
    format initialState=setFormat();//这又是啥啊
    precis prec=cout.precision(2);
    if(amt<0) cout<<"Withdrawal amount must be positive;"
                  <<"withdrawal canceled.\n";
    else if(amt<=balance) balance-=amt;
    else cout<<"Withdrawal amount of $"
             <<amt<<"exceeds your balance.\n"
             <<"Withdrawal canceled.\n";
    restore(initialState,prec);
}
double Brass::Balance() const{
    return balance;
}

void Brass::ViewAcct() const{}