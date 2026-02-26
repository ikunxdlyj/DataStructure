#include <iostream>
using namespace std;

int n;
// 寻找 >=x 且最左的数
// TODO
int findX(int arr[], int x) {
    int l = 0, r = n - 1;
    int ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] < x) {
            l = mid + 1;
        }else{
            ans=mid;
            r=mid-1;
        }
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}