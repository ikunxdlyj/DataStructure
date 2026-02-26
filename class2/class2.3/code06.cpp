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

LinkedList *splitLinkedList(LinkedList list) {
    LinkedList list1 = nullptr, list2 = nullptr;
    ListNode *cur = list;
    ListNode *cur1 = nullptr;
    ListNode *cur2 = nullptr;
    ListNode *next = nullptr;
    int index = 1;
    while (cur != nullptr) {
        next = cur->next;
        cur->next = nullptr;
        if (index % 2 == 1) {
            if (list1 == nullptr) {
                list1 = cur;
                cur1 = list1;
            } else {
                cur1->next = cur;
                cur1 = cur1->next;
            }
        } else {
            if (list2 == nullptr) {
                list2 = cur;
                cur2 = list2;
            } else {
                cur2->next = cur;
                cur2 = cur2->next;
            }
        }
        index++;
        cur = next;
    }
    LinkedList *ans = new LinkedList[2];
    ans[0] = list1;
    ans[1] = list2;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    LinkedList list = buildList(arr, 10);
    printList(list);
    LinkedList *ans = splitLinkedList(list);
    printList(ans[0]);
    printList(ans[1]);
    destroyList(list);
    return 0;
}