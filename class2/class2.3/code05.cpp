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
// https://leetcode.cn/problems/3u1WK4/submissions/685165773/
ListNode* findIntersectionNode(LinkedList list1, LinkedList list2){
    if(list1==nullptr||list2==nullptr){
        return nullptr;
    }
    int diff=0;
    ListNode* cur=list1;
    while(cur->next!=nullptr){
        cur=cur->next;
        diff++;
    }
    cur=list2;
    while(cur->next!=nullptr){
        cur=cur->next;
        diff--;
    }
    // 保证list1为长链表,list2为短链表
    if(diff<0){
        swap(list1,list2);
        diff=-diff;
    }
    while(diff!=0){
        list1=list1->next;
        diff--;
    }
    while(list1!=list2){
        list1=list1->next;
        list2=list2->next;
    }
    return list1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}