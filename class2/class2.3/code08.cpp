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

LinkedList getSameVals(LinkedList list1, LinkedList list2) {
    if (list1 == nullptr || list2 == nullptr) {
        return nullptr;
    }
    LinkedList ansPre = new ListNode(-1);
    ListNode *cur = ansPre;
    ListNode *cur1 = list1;
    ListNode *cur2 = list2;
    while (cur1 != nullptr && cur2 != nullptr) {
        if (cur1->val == cur2->val) {
            cur->next = new ListNode(cur1->val);
            cur = cur->next;
            cur1 = cur1->next;
            cur2 = cur2->next;
        } else {
            if (cur1->val < cur2->val) {
                cur1 = cur1->next;
            } else {
                cur2 = cur2->next;
            }
        }
    }
    ListNode *temp = ansPre->next;
    delete ansPre;
    return temp;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int arr1[6] = {1, 2, 3, 4, 5, 6};
    int arr2[6] = {2, 3, 4, 5, 6, 7};
    LinkedList list1 = buildList(arr1, 6);
    LinkedList list2 = buildList(arr2, 6);
    printList(list1);
    printList(list2);
    LinkedList ans = getSameVals(list1, list2);
    printList(ans);
    destroyList(list1);
    destroyList(list2);
    destroyList(ans);
    return 0;
}