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

//iterato tech 

ListNode* reverseList(ListNode* head) {

    if(head == NULL || head -> next == NULL) {

        return head;
    }

    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* forward = NULL;

    while(curr != NULL) {

        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

//recursive tech

void reverse(ListNode* &head, ListNode* curr, ListNode* prev) {

    //base case
    if(curr == NULL) {

        head = prev;
        return;
    }

    ListNode* forward = curr -> next;
    reverse(head, forward, curr);
    curr -> next = prev;
}

ListNode* reverseList(ListNode* head) {

    ListNode* curr = head;
    ListNode* prev = NULL;
    reverse(head, curr, prev);
    return head;
}

// 3rd approch

ListNode* reverse1(ListNode* head) {

    //base case
    if(head == NULL || head -> next == NULL) {

        return head;
    }

    ListNode* chotaHead = reverse1(head -> next);

    head -> next -> next = head;
    head -> next = NULL;

    return chotaHead;
}

ListNode* reverseList(ListNode* head) {

    return reverse1(head);
}

