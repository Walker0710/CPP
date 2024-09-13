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

void insertAtTail(ListNode* &head,ListNode* &tail, int d) {

    //new ListNode create
    ListNode* temp = new ListNode(d);

    if(head == NULL) {

        head = temp;
        tail = temp;
        return ;
    }

    else {
    tail -> next = temp;
    tail = temp;
    }
}

ListNode* reverse(ListNode* head) {

    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* Next = NULL;

    while(curr != NULL) {

        Next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = Next;
    }

    return prev;
}

ListNode* add( ListNode* first, ListNode* second) {

    int sum = 0;
    int carry = 0;
    int digit;

    ListNode* ansHead = NULL;
    ListNode* ansTail = NULL;

    while(first != NULL && second != NULL) {

        sum = first -> val + second -> val + carry;

        carry = sum/10;
        digit = sum%10;

        insertAtTail(ansHead, ansTail, digit);

        first = first -> next;
        second = second -> next;
    }

    while(first != NULL) {

        int sum = carry + first -> val;
        int digit = sum%10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum/10;
        first = first -> next;
    }

    while(second != NULL) {

        int sum = carry + second -> val;
        int digit = sum%10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum/10;
        second = second -> next;
    }

    while(carry != 0) {

        int sum = carry;
        int digit = sum%10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum/10;
    }

    return ansHead;
}

ListNode* addTwoNumbers(ListNode* first, ListNode* second) {

    first = reverse(first);
    second = reverse(second);

    ListNode* ans = add(first, second);
    ans = reverse(ans);
    return ans;
}