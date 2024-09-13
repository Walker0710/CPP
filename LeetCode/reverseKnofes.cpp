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

ListNode* swapPairs2(ListNode* head, int k) {

    //base case
    if(head == NULL) {

        return head;
    }

    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* fur =  NULL;

    int size = 0;
    ListNode* yo = curr;

    while(yo != NULL) {

        size++;
        yo = yo -> next;
    }

    if(size < k) {

        return head;
    }

    int t = k;

    while(t && curr != NULL) {

        fur = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = fur;

        t--;
    }

    head -> next = swapPairs2(curr, k);

    return prev;
}