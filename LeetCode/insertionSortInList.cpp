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

ListNode* insertionSortList(ListNode* head) {

    int size = 0;
    ListNode* curr = head;
    
    while(curr != NULL) {

        size++;
        curr = curr -> next;
    }

    int ii = 1;

    while(ii <= size) {

        ListNode* key = head -> next;
        ListNode* j = head;

        int counter = 0;

        while(counter >= ii - 1 && j -> data < key -> data) {


        }
    }

}