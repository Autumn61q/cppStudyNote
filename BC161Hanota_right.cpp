#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
void hanoi(char a, char b, char c, int n) {
    if (n==0) return ;
    hanoi(a, b, c, n-1);
    cnt++;
    hanoi(c, b, a, n-1);
    cnt++;
    hanoi(a, b, c, n-1);
}

int main() {
    int n;
    while (cin>>n) {
        cnt = 0;
        hanoi('a', 'b', 'c', n);
        cout<<cnt<<endl;
    }
    
    return 0;
}