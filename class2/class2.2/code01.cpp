#include <iostream>
using namespace std;

// 全局变量，记录数组当前元素个数
int n;

/**
 * 从数组中移除最小值元素
 * @param arr 待处理的数组
 * @return 返回被移除的最小值，如果数组为空则返回-1
 */
int removeMinVal(int arr[]) {
    // 检查数组是否为空
    if (n == 0) {
        return -1;
    }
    
    // 初始化最小值为第一个元素
    int minVal = arr[0];
    // 记录最小值的索引位置
    int minIndex = 0;
    
    // 遍历数组寻找最小值
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            // 更新最小值
            minVal = arr[i];
            // 更新最小值索引
            minIndex = i;
        }
    }
    
    // 用最后一个元素替换最小值位置的元素
    arr[minIndex] = arr[n - 1];
    // 数组元素个数减1
    n--;
    // 返回被移除的最小值
    return minVal;
}

int main() {
    // 关闭iostream与stdio的同步，提高IO效率
    ios::sync_with_stdio(false);
    // 解除cin与cout的绑定，进一步提高效率
    cin.tie(nullptr);
    
    // 初始化测试数组
    int arr[6] = {1, -2, 3, 4, 5, 6};
    // 设置数组初始元素个数
    n = 6;
    // 调用函数移除并获取最小值
    int res = removeMinVal(arr);
    // 输出被移除的最小值(-2)
    cout << res << endl;
    
    cout << "----------" << endl;
    
    // 输出处理后的数组元素
    for (size_t i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}