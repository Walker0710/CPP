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

ListNode* swapPairs(ListNode* head) {

    //base case
    if(head == NULL) {

        return head;
    }

    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* fur =  NULL;

    int t = 2;

    while(t && curr != NULL) {

        fur = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = fur;

        t--;
    }

    head -> next = swapPairs(curr);

    return prev;
}