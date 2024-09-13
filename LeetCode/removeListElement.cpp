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

ListNode* removeElements(ListNode* head, int val) {

    ListNode* dummy = new ListNode(0);
    dummy -> next = head;
    ListNode* prev = dummy;
    ListNode* curr = dummy -> next;

    while(curr != NULL) {

        if(curr -> data == val) {

            ListNode* forw = curr -> next;
            prev -> next = forw;
            curr -> next = NULL;
            curr = forw;
        }

        else {

            prev = curr;
            curr = curr -> next;
        }
    }

    return dummy -> next;
}