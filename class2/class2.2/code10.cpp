#include <iostream>
using namespace std;

void reverse(int nums[],int l,int r){
    while(l<r){
        swap(nums[l++],nums[r--]);
    }
}
void cyclicLeftShiftArray(int arr[],const int n, int p){
    p%=n;
    reverse(arr,0,n-1);
    reverse(arr,0,n-p-1);
    reverse(arr,n-p,n-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int arr[7]={0,1,2,3,4,5,6};
    int n=7;
    int p=3;
    cyclicLeftShiftArray(arr,n,p);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}