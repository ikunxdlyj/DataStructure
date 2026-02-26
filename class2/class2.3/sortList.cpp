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
ListNode *getMid(LinkedList List) {
    ListNode *slow = List, *fast = List;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode *merge(LinkedList list1, LinkedList list2) {
    if (list1 == nullptr) {
        return list2;
    }
    if (list2 == nullptr) {
        return list1;
    }
    ListNode *ans = nullptr;
    ListNode *cur = nullptr;
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            if (ans == nullptr) {
                ans = list1;
                cur = ans;
            } else {
                cur->next = list1;
                cur = cur->next;
            }
            list1 = list1->next;
        } else {
            if (ans == nullptr) {
                ans = list2;
                cur = ans;
            } else {
                cur->next = list2;
                cur = cur->next;
            }
            list2 = list2->next;
        }
    }
    list1 == nullptr ? cur->next = list2 : cur->next = list1;
    return ans;
}

LinkedList sortList(LinkedList list) {
    if (list == nullptr || list->next == nullptr) {
        return list;
    }
    ListNode *mid = getMid(list);
    ListNode *midNext = mid->next;
    mid->next = nullptr;
    LinkedList left = sortList(list);
    LinkedList right = sortList(midNext);
    return merge(left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[6] = {10,9,8,7,5,6};
    LinkedList list = buildList(arr, 6);
    cout << "origin:" << endl;
    printList(list);
    cout << "sort:" << endl;
    printList(sortList(list));
    return 0;
}