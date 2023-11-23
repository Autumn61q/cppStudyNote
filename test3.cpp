#include <iostream>
using namespace std;

int main()
{
    char ch1, ch2;
    cin.get(ch1);
    cin.get(ch2);
    cout << "ch1 = " << ch1 << endl;
    cout << "ch2 = " << ch2 << endl;
    cin.unget();
    cin.get(ch2);
    cout << "ch2 = " << ch2 << endl;
    return 0;
}