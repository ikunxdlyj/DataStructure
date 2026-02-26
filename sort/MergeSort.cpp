#include <iostream>
using namespace std;
int N;
int arr[100001];
int help[100001];
void merge(int l, int mid, int r) {
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        help[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
    }
    while (i <= mid) {
        help[k++] = arr[i++];
    }
    while (j <= r) {
        help[k++] = arr[j++];
    }

    for (k = l; k <= r; k++) {
        arr[k] = help[k - l];
    }
}
void mergeSort(int l, int r) {
    if (l >= r) {
        return;
    }
    int mid = l + ((r - l) >> 1);
    // int mid = l + (r - l) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    merge(l, mid, r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    mergeSort(0, N - 1);
    for (int i = 0; i < N - 1; i++) {
        cout << arr[i] << " ";
    }
    cout << arr[N - 1] << "\n";
    return 0;
}