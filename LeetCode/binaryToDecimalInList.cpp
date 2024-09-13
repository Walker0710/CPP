#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class ListNode {

    public:
    int val;
    ListNode* next;

    //constructor
    ListNode(int d) {

        this -> val = d;
        this -> next = NULL;
    }
}; 

    int getDecimalValue(ListNode* head) {
        int i=0;
        ListNode *ptr=head;
        while(ptr!=nullptr)
        {
            i+=ptr->val;
            ptr=ptr->next;
            if(ptr!=nullptr)
                 i=i*2;
        }
        return i;
    }