#include <iostream>
using namespace std;

// n为arr1的长度，m为arr2的长度
int n, m;
int arr1[10001], arr2[10001];
int arr3[20001];
void mergeTwoLists(int arr1[], int arr2[]) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }
    while (i < n) {
        arr3[k++] = arr1[i++];
    }
    while (j < m) {
        arr3[k++] = arr2[j++];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    n = 5;
    m = 5;
    int arr1[5] = {1, 3, 5, 7, 9};
    int arr2[5] = {2, 4, 6, 8, 10};
    mergeTwoLists(arr1, arr2);
    cout << "arr1:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    cout << "arr2:" << endl;
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    cout << "After merge:" << endl;
    for (int i = 0; i < n + m; i++) {
        cout << arr3[i] << " ";
    }
    return 0;
}