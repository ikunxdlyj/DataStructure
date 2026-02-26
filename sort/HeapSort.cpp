#include <iostream>
using namespace std;
int N;
int arr[100001];
void heapify(int i, int size) {
    int l = 2 * i + 1;
    while (l < size) {
        int best = l + 1 < size && arr[l + 1] > arr[l] ? l + 1 : l;
        best = arr[best] > arr[i] ? best : i;
        if (best == i) {
            break;
        }
        swap(arr[i], arr[best]);
        i = best;
        l = 2 * i + 1;
    }
}
void heapSort() {
    for (int i = N - 1; i >= 0; i--) {
        heapify(i, N);
    }
    int size = N;
    while (size > 1) {
        swap(arr[0], arr[size - 1]);
        size--;
        heapify(0, size);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    heapSort();
    for (int i = 0; i < N - 1; i++) {
        cout << arr[i] << " ";
    }
    cout << arr[N - 1] << "\n";

    return 0;
}