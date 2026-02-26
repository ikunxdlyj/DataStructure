#include <iostream>
#include <vector>
using namespace std;

vector<int> getSameVals(
    vector<int> &arr1,
    vector<int> &arr2,
    vector<int> &arr3) {
    vector<int> ans;
    int i = 0, j = 0, k = 0;
    while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
        int val1 = arr1[i], val2 = arr2[j], val3 = arr3[k];
        if (val1 == val2 && val2 == val3) {
            ans.push_back(val1);
            i++, j++, k++;
        } else {
            int minVal = min(val1, min(val2, val3));
            if (val1 == minVal) {
                i++;
            } else if (val2 == minVal) {
                j++;
            } else {
                k++;
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr1 = {1, 3, 4, 5, 7, 9};
    vector<int> arr2 = {2, 3, 4, 5, 6, 8, 10};
    vector<int> arr3 = {0, 3, 4, 5, 6};
    vector<int> ans = getSameVals(arr1, arr2, arr3);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
