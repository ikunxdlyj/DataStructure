#include <climits>
#include <iostream>

int add(int a, int b) {
    int sum = a ^ b;
    int carry = (a & b) << 1;
    while (carry != 0) {
        int temp = sum;
        sum ^= carry;
        carry = (temp & carry) << 1;
    }
    return sum;
}

// 取相反数
int neg(int a) {
    if (a == INT_MIN) {
        throw std::runtime_error("Overflow: Cannot negate INT_MIN");
    }
    return add(~a, 1);
}

// a - b 等价于 a + (-b)
int sub(int a, int b) {
    return add(a, neg(b));
}

int mul(int a, int b) {
    int x = a >= 0 ? a : neg(a);
    int y = b >= 0 ? b : neg(b);
    int mulRes = 0;
    int flag = ((a >> 31) & 1) ^ ((b >> 31) & 1);
    while (y != 0) {
        if ((y & 1) == 1) {
            mulRes = add(mulRes, x);
        }
        x <<= 1;
        y >>= 1;
    }
    return flag == 0 ? mulRes : neg(mulRes);
}

int main() {
    using namespace std;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int offset = 1 << 15;
    for (int i = 0; i < 1000; i++) {
        int a = rand() - offset;
        int b = rand() - offset;
        if ((a + b) != (add(a, b))) {
            cout << "error" << endl;
            cout << "a:" << a << "\n";
            cout << "b:" << b << "\n";
            cout << "a+b:" << a + b << "\n";
            cout << "add(a,b):" << add(a, b) << "\n";
        }
        if ((a - b) != (sub(a, b))) {
            cout << "error" << endl;
            cout << "a:" << a << "\n";
            cout << "b:" << b << "\n";
            cout << "a-b:" << a - b << "\n";
            cout << "sub(a,b):" << sub(a, b) << "\n";
        }
        if ((a * b) != (mul(a, b))) {
            cout << "error" << endl;
            cout << "a:" << a << "\n";
            cout << "b:" << b << "\n";
            cout << "a*b:" << a * b << "\n";
            cout << "mul(a,b):" << mul(a, b) << "\n";
        }
    }
    cout << "done" << endl;
    return 0;
}