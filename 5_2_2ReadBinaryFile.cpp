//Read Binary File
    // 二进制方式读文件主要利用流对象调用成员函数read
    // 函数原型：istream& read(char *buffer,int len)
    // 参数解释：字符指针buffer指向内存中的一段存储空间，len是读写的字节数

#include<iostream>
#include<fstream>
using namespace std;
class Test{
public:
    char name[10];
};

int main(){
    ifstream ifs;
    ifs.open("./testBinary.txt",ios::in|ios::binary);
    //判断文件是否打开成功：
    if(!ifs.is_open()){
        cout<<"fail to open"<<endl;
        return 1;
    }
    Test t1;
    ifs.read((char*)&t1,sizeof(t1));
    cout<<t1.name<<endl;
    ifs.close();
    return 0;
}