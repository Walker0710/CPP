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

ListNode* rotateRight(ListNode* head, int k) {

    if(head == NULL || head -> next == NULL) {

        return head;
    }    

    ListNode* p2 = head;
    int size = 1;

    while(p2 -> next != NULL) {

        p2 = p2 -> next;
        size++;
    }

    ListNode* p1 = head;
    ListNode* p11 = head -> next;

    int t = k%size;
    int counter = size - t;

    while(counter) {

        p2 -> next = p1;
        p1 -> next = NULL;
        p2 = p1;
        p1 = p11;
        p11 = p11 -> next;
        counter--;
    }

    return p1;
}