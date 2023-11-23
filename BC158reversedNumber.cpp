#include<iostream>
#include<string>
#include<vector>
using namespace std;

string n;
int sys;
vector<int> v;
vector<int> rev;
void str2vector(string str,vector<int> &v){
    for(int i=0;i<str.length();i++){
        if(n[i]>='0'&&n[i]<=9) v.push_back(n[i]);
        else v.push_back(n[i]-'A'+10);
    }
}
void reVector(vector<int> &v,vector<int> &rev){
    for(int i=v.size()-1;i>=0;i--){
        rev.push_back(v[i]);
    }
}
void add(vector<int> &v,vector<int> &rev){
    for(int i=v.size()-1;i>=0;i--){
        v[i]+=rev[i]
        v[i+1]+=v[i]/sys;  //十六进制怎么办？如果多了一位怎么办？
        
    }
}

int main(){
    cin>>sys>>n;
    str2vector(n,v);
    reVector(v,rev);
    add(v,rev);
    return 0;
}