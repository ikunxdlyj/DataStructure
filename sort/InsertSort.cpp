#include <iostream>
using namespace std;
void insertSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j - 1 >= 0 && arr[j - 1] > arr[j]; j--) {
            swap(arr[j], arr[j - 1]);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int arr[6] = {5, 4, 3, 2, 1, 0};
    insertSort(arr, 6);
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}