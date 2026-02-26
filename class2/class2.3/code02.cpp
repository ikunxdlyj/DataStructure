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

LinkedList removeMinVal(LinkedList list) {
    if (list == nullptr || list->next == nullptr) {
        return nullptr;
    }
    LinkedList dummy = new ListNode(-1);
    dummy->next = list;
    ListNode *minPre = dummy;
    ListNode *min = list;
    ListNode *cur = list;
    while (cur != nullptr) {
        if (cur->val < min->val) {
            while (min != cur) {
                min = min->next;
                minPre = minPre->next;
            }
        }
        cur = cur->next;
    }

    minPre->next = minPre->next->next;
    delete min;

    ListNode *head = dummy->next;
    delete dummy;
    return head;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int arr[6] = {6, -100, -3, 3, 2, 1};
    LinkedList list = buildList(arr, 6);
    printList(list);
    list = removeMinVal(list);
    printList(list);
    destroyList(list);
    return 0;
}