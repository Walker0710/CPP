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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    
    if(list1 == NULL) {

        return list2;
    }

    if(list2 == NULL) {

        return list1;
    }

    ListNode* ansHead = NULL;
    ListNode* ansTail = NULL;

    while(list1 != NULL && list2 != NULL)  {

        if(list1 -> data <= list2 -> data) {

            insertAtTail(ansHead, ansTail, list1 -> data);
            list1 = list1 -> next;
        }

        else {

            insertAtTail(ansHead, ansTail, list2 -> data);
            list2 = list2 -> next;
        }
    }

    while(list1 != NULL) {

        insertAtTail(ansHead, ansTail, list1 -> data);
        list1 = list1 -> next;
    }

    while(list2 != NULL) {

        insertAtTail(ansHead, ansTail, list2 -> data);
        list2 = list2 -> next;
    }

    return ansHead;
}

//2nd approch

ListNode* solve(ListNode* first, ListNode* second) {

    //if only one element is present 
    if(first -> next == NULL) {

        first -> next = second;
        return first;
    }

    ListNode* curr1 = first;
    ListNode* next1 = curr1 -> next;
    ListNode* curr2 = second;
    ListNode* next2 = curr2 -> next;

    while(next1 != NULL && curr2 != NULL) {

        if((curr2 -> data >= curr1 -> data) && (curr2 -> data <= next1 -> data)) {

            //add node btw the first list
            curr1 -> next = curr2;
            next2 = curr2 -> next;
            curr2 -> next = next1;

            //update ponters  
            curr1 = curr2;
            curr2 = next2;
        }

        else {

            //curr1 aur next1 ko aage badhan h
            curr1 = next1;
            next1 = next1 -> next;
            
            if(next1 == NULL) {

                curr1 -> next = curr2;
                return first;
            }
        }
    }

    return first;
}

ListNode* sortTwoList2nd(ListNode* list1, ListNode* list2) {

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