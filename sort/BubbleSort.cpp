#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int end = n - 1; end > 0; end--) {
        for (int i = 1; i <= end; i++) {
            if (arr[i - 1] > arr[i]) {
                swap(arr[i - 1], arr[i]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 100; i++) {
        int n = rand() % 10000;
        int arr[n];
        int offset = rand() % 10000 / 2;
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % 10000 - offset;
        }
        bubbleSort(arr, n);
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                cout << "Error" << endl;
                return 0;
            }
        }
    }
    cout << "OK" << "\n";
    return 0;
}