#include <bits/stdc++.h>

using namespace std;

// << ,
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

bool hasCycle(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        return true;
    }

    return false;
}

bool hasCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;

    while(fast != NULL && fast -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;

        if(fast == slow) {
            return true;
        }
    }

    return false;
}