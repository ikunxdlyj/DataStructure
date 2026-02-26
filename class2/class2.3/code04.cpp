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

LinkedList removeValBetweenXAndY(LinkedList list, int x, int y) {
    if (list == nullptr) {
        return nullptr;
    }
    ListNode *dummy = new ListNode(-1);
    dummy->next = list;
    ListNode *pre = dummy;
    while (pre->next != nullptr) {
        if (pre->next->val >= x && pre->next->val <= y) {
            ListNode *temp = pre->next;
            pre->next = pre->next->next;
            delete temp;
        } else {
            pre = pre->next;
        }
    }
    ListNode* head=dummy->next;
    delete dummy;
    return head;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[6]={2,2,3,4,5,2};
    LinkedList list = buildList(arr, 6);
    printList(list);
    list = removeValBetweenXAndY(list, 2, 4);
    printList(list);
    destroyList(list);
    return 0;
}