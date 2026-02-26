#include <iostream>
using namespace std;
// 摩尔投票
int majorityElement(int arr[], int n) {
    int votes = 1, res = arr[0];
    for (int i = 1; i < n; i++) {
        if (votes == 0) {
            res = arr[i];
            votes = 1;
        } else if (res == arr[i]) {
            votes++;
        } else {
            votes--;
        }
    }
    votes = 0;
    for (int i = 0; i < n; i++) {
        if (res == arr[i]) {
            votes++;
        }
    }
    if (votes <= n / 2) {
        return -1;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int arr[5] = {1, 0, 4, 2, 2};
    int n = 5;
    int res = majorityElement(arr, n);
    cout << res << endl;
    return 0;
}