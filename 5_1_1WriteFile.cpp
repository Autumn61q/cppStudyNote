// 5 文件操作：
//     程序运行产生的数据都属于临时数据，程序一旦运行结束就都会被释放
//     通过数据可将数据永久化
//     cpp中对文件操作需要包含头文件<fstream>

//     文件类型分为两种：
//         1.文本文件：文件以文本的ASCII码形式储存在计算机中（没有特殊需求时选）
//         2.二进制文件：文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂它们（不想让别人看懂而又不想加密时选）
    
//     操作文件的三大类：(they are class in cpp standard library,它们都是头文件fstream下的三个类)
//     输入是指程序从外部世界获取数据，输出是指程序向外部世界发送数据。
//     输入流用于从外部设备（例如键盘、文件）读取数据，输出流用于向外部设备（例如显示器、文件）写入数据。
//     我们是站在程序的立场考虑输入和输出的
//         1.ofstream:写操作（从程序往外部写东西，所以是输出）
//         2.ifstream:读操作（外部把内容传递给程序本身，所以是输入）
//         3.fstream:读写操作

//5_1_1 write file
    // procedure:
    //     1.include the header file 
    //         #include<fstream>
    //     2.creat flow object(流对象)
    //         ofstream ofs;(ofs这个名字无所谓)
    //     3.open the file(通过这个流对象来写)
    //         ofs.open("file path","the way to open it")
    //     4.write your data 
    //         ofs<<"blah..blah....";
    //     5.close file
    //         ofs.close();

    // 文件打开方式：
    //     ios::in 为读文件而打开文件
    //     ios::out 为写文件而打开文件（文件不存在则先创建
    //     ios::ate 初始位置是文件尾
    //     ios::app 追加方式写文件
    //     ios::trunc 如果文件存在则先删除在创建
    //     ios::binary 二进制方式

    //     注：文件打开方式可以配合使用，利用|运算符
    //         例：用二进制方式写文件： ios::out|ios::binary

#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream ofs;//这个地方可以按照需求写需要的类
    ofs.open("./test.txt",ios::out);//(如果不写打开方式，则默认为输出，对于ifstream则默认为输入)
    ofs<<"刚刚小小休息了一下"<<endl;//你可以想一下，cout<<...是输出到显示器上，所以说ofs<<就是输出到ofs对象代表的文件中
    ofs<<"今天是晴天！"<<endl;
    ofs<<"今天我的羽毛球拍要到了！"<<endl;
    ofs.close();
    return 0;
}