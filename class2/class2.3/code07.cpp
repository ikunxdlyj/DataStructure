#include <iostream>
using namespace std;
typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
} ListNode, *LinkedList;

// typedef ListNode* LinkedList;
// using LinkedList=ListNode*;
LinkedList buildList(int arr[], int n) {
    LinkedList list = nullptr;
    ListNode *cur = nullptr;
    for (int i = 0; i < n; i++) {
        if (list == nullptr) {
            list = new ListNode(arr[i]);
            cur = list;
        } else {
            cur->next = new ListNode(arr[i]);
            cur = cur->next;
        }
    }
    return list;
}

void destroyList(LinkedList list) {
    ListNode *cur = list;
    while (cur != nullptr) {
        ListNode *temp = cur;
        cur = cur->next;
        delete temp;
    }
}
void printList(LinkedList list) {
    ListNode *cur = list;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

LinkedList removeSameVal(LinkedList list) {
    if (list == nullptr || list->next == nullptr) {
        return list;
    }
    ListNode *pre = list;
    while (pre->next != nullptr) {
        if (pre->val == pre->next->val) {
            ListNode *temp = pre->next;
            pre->next = pre->next->next;
            delete temp;
        } else {
            pre = pre->next;
        }
    }
    return list;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[6] = {1, 2, 2, 3, 3, 6};
    LinkedList list = buildList(arr, 6);
    printList(list);
    list = removeSameVal(list);
    printList(list);
    return 0;
}