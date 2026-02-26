#include <iostream>
using namespace std;
int n;
void removeSameVal(int arr[]) {
    int i, j;
    for (i = 1, j = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            arr[j++] = arr[i];
        }
    }
    n = j;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int arr[10] = {1, 2, 3, 4, 5, 5, 5, 5, 6, 6};
    n = 10;

    removeSameVal(arr);

    for (int i = 0; i < n; i++) { // 使用新的数组长度进行遍历
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}