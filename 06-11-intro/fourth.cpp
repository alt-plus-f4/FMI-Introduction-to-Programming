#include <iostream>

using namespace std;

int main(){
    int a = 5;
    int b = 12;

    a = a + b;
    b = a - b;
    a = a - b;
    
    cout << a << ' ' << b << '\n';

    return 0;
}

