#include<iostream>
using namespace std;

int add(const int &a, const int &b);

int main() {
    cout << add(1, 2) << endl;
    return 0;
}

int add(const int &a, const int &b) {
    return a + b;
}
