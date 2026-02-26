#include <iostream>
using namespace std;

int n;

/*
    https://leetcode.cn/problems/move-zeroes/
 * 删除数组中所有等于x的元素
 * */
int removeValEqualX1(int arr[], int x) {
    if (n == 0) {
        return 0;
    }
    int cnt = 0;
    for (int i = 0, j = 0; i < n; i++) {
        // 将X看作空位，遇到有效值（不为X的值）就往前放
        // 放完后，j就指向了第一个空位
        // 用swap 不用arr[j]=arr[i]即不用覆盖的方式
        // 是为了保持数组有效元素的个数始终不变
        if (arr[i] != x) {
            swap(arr[i], arr[j++]);
            cnt++;
        }
    }
    n -= cnt;
    return cnt;
}
int removeValEqualX2(int arr[], int x) {
    if (n == 0) {
        return 0;
    }
    // 栈的做法(将数组arr本身看作一个栈)
    int cnt = 0;
    for (int i = 0, j = 0; i < n; i++) {
        if (arr[i] != x) {
            arr[j++] = arr[i];
            cnt++;
        }
    }
    n-=cnt;
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[6] = {2, 1, 2, 2, 4, 5};
    n = 6;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n"
         << "----------------" << "\n";
    int cnt = removeValEqualX2(arr, 2);
    cout << cnt << "\n";
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}