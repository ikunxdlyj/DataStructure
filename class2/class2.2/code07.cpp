#include <iostream>
using namespace std;

int n, m;
void reverse(int nums[], int l, int r) {
    int i = l, j = r;
    while (i < j) {
        swap(nums[i++], nums[j--]);
    }
}
void swapArr(int arr[]) {
    reverse(arr, 0, n + m - 1);
    reverse(arr, 0, m - 1);
    reverse(arr, m, n + m - 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    n = 5;
    m = 3;
    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << "Before swap:" << endl;
    for (int i = 0; i < n + m; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    swapArr(arr);
    for (int i = 0; i < n + m; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}