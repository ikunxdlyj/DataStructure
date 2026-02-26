#include <iostream>
using namespace std;

void swap(int i, int j, int arr[]) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void reverseArr(int arr[], const int n) {
    int i = 0, j = n - 1;
    while (i < j) {
        swap(i, j, arr);
        i++;
        j--;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[6]={1,2,3,4,5,6};
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
    cout<<"--------"<<endl;
    reverseArr(arr, 6);
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}