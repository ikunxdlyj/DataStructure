#include <iostream>
using namespace std;
int N;
int arr[100001];

int first, last;
void partition(int l, int r, int pivot) {
    first = l;
    last = r;
    int index = l;
    while (index <= last) {
        if (arr[index] < pivot) {
            swap(arr[index++], arr[first++]);
        } else if (arr[index] > pivot) {
            swap(arr[index], arr[last--]);
        } else {
            index++;
        }
    }
}
void quickSort(int l, int r) {
    if (l >= r) {
        return;
    }
    int randomIndex = rand() % (r - l + 1) + l;
    int pivot = arr[randomIndex];
    partition(l, r, pivot);
    quickSort(l, first - 1);
    quickSort(last + 1, r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    quickSort(0, N - 1);
    for (int i = 0; i < N - 1; i++) {
        cout << arr[i] << " ";
    }
    cout << arr[N - 1] << "\n";
    return 0;
}