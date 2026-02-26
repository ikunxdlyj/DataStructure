#include <iostream>
using namespace std;

int n;
int removeArrFromSToT(int s, int t, int arr[]) {
    if (s > t) {
        return -1;
    }
    if (s < 0 || t > n - 1) {
        return -1;
    }
    int removeLen = t - s + 1;
    for (int i = t + 1; i < n; i++) {
        arr[i - removeLen] = arr[i];
    }
    n -= removeLen;
    return removeLen;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    n = 10;

    int s = 4;
    int t = 7;
    int removeLen = removeArrFromSToT(s, t, arr);
    cout << "removeLen:" << removeLen << endl;
    cout << "s:" << s << " t:" << t << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}