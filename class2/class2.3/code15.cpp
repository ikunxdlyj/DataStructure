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

bool hasCycle(LinkedList list){
    if(list==nullptr){
        return false;
    }
    ListNode *slow=list;
    ListNode *fast=list;
    while(fast->next!=nullptr&&fast->next->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int arr[6] = {1, 2, 3, 4, 5, 6};
    LinkedList list = buildList(arr, 6);
    // ListNode *cur = list;
    // while (cur->next != nullptr) {
    //     cur = cur->next;
    // }
    // cur->next = list;
    cout<<hasCycle(list)<<endl;
    return 0;
}