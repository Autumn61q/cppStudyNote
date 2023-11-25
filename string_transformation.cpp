//这个是cpp作业HW2的一道题
#include<iostream>
#include<fstream>
using namespace std;


void deal_node1(char left,fstream &f,void (*p)(int,int,int,int,int),int p1,int p2,int p3){    //determine whether the characters from both sides of hyper can satisfy the condition of being decompressed
    char right;
    f.get();
    f.get(right);
    if(((left>='a'&&left<='z')&&(right>='a'&&right<='z'))||((left>='0'&&left<='9')&&(right>='0'&&right<='9'))){
        if(left<right) p(left,right,p1,p2,p3);  //if they satisfy, then call deal_node2
    }
    else cout<<left<<'-'<<right;    //else, output the original content
}
void deal_node2(int left,int right,int p1,int p2,int p3){   //print the modified segment
    cout<<(char)left;   //firstly, print the character of the left side of hyper
    if(p3==1){  //print the modified segment in increasing order
        if(p1==1){  //print the lowercase letters
            for(int i=left+1;i<right;i++){  //determind the characters which will be added
                for(int j=0;j<p2;j++) cout<<(char)i;    //determind the times that characters will be duplicated and then print
            }
        }
        else{   //print the uppercase letters
            for(int i=left+1-'a'+'A';i<right-'a'+'A';i++){  //determind the characters which will be added
                for(int j=0;j<p2;j++) cout<<(char)i;    //determind the times that characters will be duplicated and then print
            }
        }
    }
    else{   //print the modified segment in decreasing order, and other parts of the code actually as same as the above
        if(p1==1){
            for(int i=right-1;i>left;i--){
                for(int j=0;j<p2;j++) cout<<(char)i;
            }
        }
        else{
            for(int i=right-1-'a'+'A';i>left-'a'+'A';i--){
                for(int j=0;j<p2;j++) cout<<(char)i;
            }
        }
    }
    cout<<(char)right;  //in the end, print the right side of the hyper
}

void deal_input(fstream &f,int p1,int p2,int p3){
    char c;
    void (*p)(int,int,int,int,int)=deal_node2;  //creat a pointer pointing to deal_node2, for it is convenient to add it into the parameter list of deal_node1
    while(f.get(c)){
        if(f.peek()!='-') cout<<c;  
        else deal_node1(c,f,p,p1,p2,p3);    //if the next character of c is '-', then call deal_node1 to do a series of operation
    }
}
int main(){
    fstream f("tem.txt",ios::in|ios::trunc|ios::out);//set a variable tem to temporarily store the input
    string input;
    int p1,p2,p3;
    cin>>p1>>p2>>p3>>input;
    f<<input;   //output the content of imput to tem.txt
    f.seekg(0,ios::beg);    //put the pointer of tem.txt to the begin of it
    deal_input(f,p1,p2,p3);
    f.close();
    return 0;
}
