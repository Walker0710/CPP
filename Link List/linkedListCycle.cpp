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

//1st approch
bool hasCycle(ListNode *head) {

    if(head == NULL) {

        return false;
    }

    map<ListNode*, bool> visited;
    ListNode* temp = head;

    while(temp != NULL) {

        if(visited[temp] == true) {

            return true;
        }

        visited[temp] = true;
        temp = temp -> next;
    }

    return false;
}

//2nd approch floyd
    bool hasCycle(ListNode *head) {
	
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow)
                return true;
        }
        
        return false;
    }
