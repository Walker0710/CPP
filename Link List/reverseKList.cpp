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

ListNode* reverseKGroup(ListNode* head, int k) {

    if(!head){

        return NULL;
    }

    ListNode*prev = NULL,*curr = head,*temp =NULL;
    int count=0;
    ListNode* countTemp = head;

    while (countTemp != NULL && count < k) {

        countTemp = countTemp->next;

            count++;
        }

        if (count < k) {

            return head;
        }

    count=0;

    while(curr!=NULL && count <k){

        temp = curr->next;
        curr->next =prev;
        prev = curr;
        curr=temp;
        count++;
    }

    if(temp!=NULL){

        head->next = reverseKGroup(temp, k);

    }

    return prev;
}