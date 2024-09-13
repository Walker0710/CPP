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

ListNode* reverse(ListNode* head) {

    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* fur = NULL;

    while(curr != NULL) {

        if(curr -> next != NULL) {

            fur = curr -> next;
        }

        curr -> next = prev;
        prev = curr;
        curr = fur;
    }

    return prev;
}

ListNode* add(ListNode* l1, ListNode* l2) {

    int sum = 0;
    int carry = 0;
    int digit = 0;

    ListNode* ansHead = NULL;
    ListNode* anstail = NULL;

    while(l1 -> next != NULL && l2 != NULL) {

        sum = l1 -> data + l2 -> data + carry;

        carry = sum/10;
        digit = sum%10;

        insertAtTail(ansHead, anstail, digit);

        l1 = l1 -> next;
        l2 = l2 -> next;
    }

    while(l1 -> next != NULL) {

        sum = l1 -> data + carry;
        digit = sum%10;
        carry = sum/10;

        insertAtTail(ansHead, anstail, digit);

        l1 = l1 -> next;
    }

    while(l2 -> next != NULL) {

        sum = l2 -> data + carry;
        digit = sum%10;
        carry = sum/10;

        insertAtTail(ansHead, anstail, digit);

        l2 = l2 -> next;
    }

    while(carry != 0) {

        sum = carry;
        digit = sum%10;
        carry = sum/10;

        insertAtTail(ansHead, anstail, digit);
    }

    return ansHead;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    ListNode* ans = add(l1, l2);
    ans = reverse(ans);

    return ans;
}

//2nd approch

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;

        if (l1 != nullptr) {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2 != nullptr) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;
        current->next = new ListNode(sum % 10);
        current = current->next;
    }

    ListNode* result = dummy->next;
    delete dummy;

    return result;
}

//3rd approch with recurtion

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry) {
    // Base case: both lists are empty and no carry is left
    if (l1 == nullptr && l2 == nullptr && carry == 0) {
        return nullptr;
    }

    // Calculate the sum of current digits and the carry
    int sum = carry;
    if (l1 != nullptr) {
        sum += l1->data;
        l1 = l1->next;
    }
    if (l2 != nullptr) {
        sum += l2->data;
        l2 = l2->next;
    }

    // Create a new node with the current digit
    ListNode* result = new ListNode(sum % 10);

    // Recursively call for the next digits with the updated carry
    result->next = addTwoNumbers(l1, l2, sum / 10);

    return result;
}