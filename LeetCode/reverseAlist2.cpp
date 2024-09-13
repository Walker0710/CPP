#include<iostream>

using namespace std;

class ListNode {

    public:
    int data;
    ListNode* next;

    //constructor
    ListNode(int d) {

        this -> data = d;
        this -> next = NULL;
    }
};

ListNode* reverseBetween(ListNode* head, int left, int right) {

    if (!head || left == right) {

        return head;
    }

    ListNode* leftPrev = head;
    ListNode* rightN = head;

    while(left >= 1) {

        leftPrev = leftPrev -> next;
        left--;
    }

    while(right >= 0) {

        rightN = rightN -> next;
        right--;
    }

    ListNode* leftN = leftPrev -> next;
    ListNode* rightNext = rightN -> next;
    
    ListNode* curr = leftN -> next;
    ListNode* prev = leftN;

    while(prev != rightN) {

        ListNode* forw = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forw;
    }

    leftPrev -> next = prev;
    leftN -> next = prev -> next;

    return head;
}

// A better approch
ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || left == right) {
        return head;
    }

    ListNode dummy(0);
    dummy.next = head;
    ListNode* leftPrev = &dummy;

    // Move leftPrev to the node before the left-th node
    for (int i = 1; i < left; ++i) {
        leftPrev = leftPrev->next;
    }

    ListNode* leftN = leftPrev->next;
    ListNode* rightN = leftN;

    // Move rightN to the right-th node
    for (int i = 0; i < right - left; ++i) {
        rightN = rightN->next;
    }

    ListNode* rightNext = rightN->next;
    
    ListNode* curr = leftN->next;
    ListNode* prev = leftN;

    while (prev != rightN) {
        ListNode* forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }

    leftPrev->next = rightN;
    leftN->next = rightNext;

    return dummy.next;
}