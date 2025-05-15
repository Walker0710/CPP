#include <bits/stdc++.h>

using namespace std;

// << ,

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

ListNode* reverseList(ListNode* head) {
    if(head == NULL || head -> next == NULL) {
        return head;
    }

    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* forw = NULL;

    while(curr != NULL) {

        forw = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forw;
    }

    return prev;
}