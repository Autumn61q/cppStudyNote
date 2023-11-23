// read file
//four methods to read data：method 3
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    ifstream ifs;
    ifs.open("./test.txt",ios::in);
    //判断是否打开成功：is_open()返回一个布尔类型的数据
    if(!ifs.is_open()){
        cout<<"failed to open"<<endl;
        return 1;//直接结束main函数 i.e.直接结束程序
    }
    //method 1:
    // char buf1[1024]={0};
    // int i=0;
    // while(ifs>>buf1)//用于从文件中读取数据并将其存储在buf数组中,文件读完则会返回false
    // {
    //     cout<<buf1;//而且是一个字一个字往外蹦，所以就很难设置换行操作
    // }
    //method 2:
    // char buf2[1024];
    // while(ifs.getline(buf2,sizeof(buf2))) //if buf is an array, use sizeof(buf); if a string, use buf.size()
    // {
    //     cout<<buf2<<endl;
    //     // 如果文件中存在换行符，但文件还没有到末尾，getline()函数将读取到换行符并将其存储在buf2数组中，
    //     // 然后将读取到的数据输出到标准输出设备（显示器）中。然后，while循环将继续执行，直到读取到文件末
    //     // 尾为止。因此，while(ifs.getline(buf2,sizeof(buf2)))循环条件将读取文件中的每一行数据，并将
    //     // 其输出到标准输出设备（显示器）中
    // }
    //method 3:
    string buf3;
    while(getline(ifs,buf3))//这次的getline是一个全局函数
    {
        cout<<buf3<<endl;//这个getline和method 2的效果是一样的
    }
    //method 4:
    // char c;
    // while((c=ifs.get())!=EOF)//EOF==end of file//或者你可以这样写while(inputfile.get(ch))
    // {
    //     cout<<c;//这个方法会自动换行，但是不推荐，因为一个一个读效率太低
    // }
    ifs.close();
    return 0;
}