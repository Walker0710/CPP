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

    if(head == NULL) 
    {
        head = temp;
        tail = temp;
        return;
    }

    else if(tail != NULL)
    {
        tail -> next = temp;
        tail = temp;
    }
}

ListNode* oddEvenList(ListNode* head) {

    ListNode* tail = head;

    while(tail -> next != NULL)
    {
        tail = tail -> next;
    }

    ListNode* tailFinal = tail;
    ListNode* odd = head;

    while (odd != NULL && odd -> next != NULL)
    {
        insertAtTail(head, tail, odd -> data);

        if(tail != NULL) 
        {
            tail = tail -> next;
        }
        
        odd = odd -> next -> next;
    }

    ListNode* even = head -> next;

    while (even -> next != NULL && even != NULL) 
    {
        insertAtTail(head, tail, even -> data);

        if(tail != NULL) 
        {
            tail = tail -> next;
        }

        even = even -> next -> next;
    }

    ListNode* final = head;

    while(final != tailFinal) 
    {
        final = final -> next;
    }

    return final -> next;
}

//2nd approch why this not giving correct ans
ListNode* oddEvenList(ListNode* head) {

    if(head == NULL || head -> next == NULL || head -> next -> next == NULL) 
    {
        return head;
    }

    int size = 1;
    ListNode* sizee = head;

    while (sizee != NULL)
    {
        size++;
        sizee = sizee -> next;
    }

    ListNode* curr = head;
    ListNode* forw = head -> next;
    ListNode* prev = NULL;

    while (curr -> next != NULL)
    {
        prev = curr;
        curr -> next = curr -> next -> next;
        curr = curr -> next;
    }

    if(size%2 == 1)
    {
        curr -> next = forw; 
    }

    else 
    {
        prev -> next = forw;
    }

    return head;
}

//3rd approch
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *even_start = head->next;
        
        while(odd->next && even->next){
            odd->next = even->next; //Connect all odds
            even->next = odd->next->next;  //Connect all evens
            odd = odd->next;
            even = even->next;
        }
        odd->next = even_start;   //Place the first even node after the last odd node.
        return head; 
    }