#include <iostream>
using namespace std;
// int f(int n){
//     if(n==0) return 0;
//     else if(n==1) return 1;
//     if(n%2==0) return f(n/2)+0;
//     else return f(n/2)+1;
// }递归超时

int f(int n){
    int count=0;
    while(n>0){
        if(n%2==1) count++;
        n/=2;
    }
    return count;
}//内存没有在32MB以内

// int find(int target,int n){
//     if(target==f(n)) return n;
//     return find(target,n+1);
// }递归超时

int find(int target){
    int result=0;
    for(int i=0;i<target;i++){
        int factor=1;
        for(int j=0;j<i;j++){
            factor*=2;//可以用右移运算符代替
        }
        result+=factor;
    }
    return result;
}//内存没有在32MB之内

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        cout<<f(num)<<" "<<find(f(num))<<" ";
    }
    return 0;
}