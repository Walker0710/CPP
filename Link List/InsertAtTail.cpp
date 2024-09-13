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

void insertAtTail(ListNode* &head, ListNode* &tail, int n) {

    ListNode* temp = new ListNode(n);

    if(head == NULL) {

        head = temp;
        tail = temp;
        return;
    }

    else {

        tail -> next = temp;
        tail = temp;
    }
}