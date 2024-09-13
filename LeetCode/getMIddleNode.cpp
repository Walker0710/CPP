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

//1st approch

    int countNode(ListNode* head)
    {
        int count = 0;
        for (ListNode* tmp = head; tmp; tmp = tmp->next) count++;
        return count;
    }

    ListNode* middleNode(ListNode* head) {
        int amount = countNode(head);
        int position = amount / 2 + 1;
        int count = 0;
        for (ListNode* tmp = head; tmp; tmp = tmp->next) 
        {
            count++;
            if (count == position) return tmp;
        }
        return head;
    }

//2nd approch
ListNode* getMid(ListNode* head) {

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast -> next) {

        fast = fast -> next;
        if(fast) {

            fast = fast -> next;
        }
        slow = slow -> next;    
        }

        return slow;
}