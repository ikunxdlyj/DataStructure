#include <iostream>
using namespace std;
void selectSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = arr[i], minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < min) {
                min = arr[j];
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int arr[5]={5, 4, 3, 2, 1};
    selectSort(arr, 5);
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}