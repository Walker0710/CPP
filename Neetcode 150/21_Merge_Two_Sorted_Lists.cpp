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

ListNode* solve(ListNode* list1, ListNode* list2) {

    if(list1 -> next == NULL) {

        list1 -> next = list2;
        return list1;
    }

    ListNode* curr1 = list1;
    ListNode* next1 = curr1 -> next;
    ListNode* curr2 = list2;
    ListNode* next2 = curr2 -> next;

    while(curr1 != NULL && curr2 != NULL) {

        if((curr2 -> data >= curr1 -> data) && (curr2 -> data <= next1 -> data)) {
            curr1 -> next = curr2;
            next2 = curr2 -> next;
            curr2 -> next = next1;

            curr1 = curr2;
            curr2 = next2;
        }

        else {

            curr1 = next1;
            next1 = next1 -> next;

            if(next1 == NULL) {
                curr1 -> next = curr2;
                return list1;
            }
        }
    }

    return list1;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == NULL) {
        return list2;
    }    

    if(list2 == NULL) {
        return list1;
    }

    ListNode* ans;

    if(list1 -> data <= list2 -> data) {
        ans = solve(list1, list2);
    }

    else {
        ans = solve(list2, list1);
    }

    return ans;
}