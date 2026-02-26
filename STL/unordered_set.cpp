#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_set<int> set;
    for (int i = 0; i < 10; i++) {
        set.insert(i);
    }
    // unordered_set 的 “无序” 是「不保证特定顺序」，而非「随机顺序」；
    // 你代码中 10 次遍历顺序相同，
    // 是因为元素集合、哈希表结构（桶数量、元素映射的桶位置）全程未变；
    // 只有触发哈希表重构（rehash）、删除元素、更换哈希函数 / 编译器时，
    // 遍历顺序才会改变。
    for (int i = 0; i < 3; i++) {
        for (int num : set) {
            cout << num << " ";
        }
        cout << endl;
    }
    set.insert(5);
    cout << "after insert 5:" << endl;
    for (int num : set) {
        cout << num << " ";
    }
    cout << endl;
    cout << "size:" << set.size() << endl;
    cout << "if 5 in set:" << (set.end() != set.find(5)) << endl;
    cout << "if 100 in set:" << (set.end() != set.find(100)) << endl;

    unordered_set<string> stringSet;
    stringSet.insert("hello");
    stringSet.insert("world");
    for (string s : stringSet) {
        cout << s << " ";
    }
    cout << endl;
    stringSet.insert("hello");
    for(string s:stringSet){
        cout<<s<<" ";
    }
    cout<<endl;
    cout<<"hello in set:"
        <<(stringSet.end()!=stringSet.find("hello"))
        <<endl;
    return 0;
}