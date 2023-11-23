//5.2 二进制文件
    //打开方式要指定为ios::binary

// 5.2.1 写文件
//     二进制方式写文件主要利用流对象调用成员函数write
//     函数原型：ostream& write(const char* buffer,int len);
//     参数解释：字符指针buffer指向内存中的一段存储空间，len是读写的字节数

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Test{
public:
    char name[10];//对文件进行操作，最好用C语言的字符串
    int age;
};
int main(){
    ofstream ofs;
    ofs.open("./testBinary.txt",ios::binary|ios::out);
    //或者可以把上面两步用ofstream浓缩成一步：ofstream ofs("./testBinary.txt",ios::binary|ios::out);
    Test p={"Qiuiue",19};//沿用c语言初始化的语法
    ofs.write((const char* )&p,sizeof(Test));
    string happy="I am so happy today!";
    ofs.write((const char*)&happy,sizeof(happy));
    ofs.close();
    return 0;
}