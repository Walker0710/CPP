#include<iostream>
#include<map>

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

    ListNode* floydDetectLoop(ListNode *head) {
	
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow) {

                return slow;
            }
        }
        return NULL;
    }

ListNode *detectCycle(ListNode *head) {

    if(head == NULL) {

        return NULL;
    }

    ListNode* intersection = floydDetectLoop(head);
    ListNode* slow = head;

    if(intersection == NULL) {

        return NULL;
    }

    while(slow != intersection) {

        slow = slow -> next;
        intersection = intersection -> next;
    }

    return slow;
}