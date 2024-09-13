#include<iostream>
#include<algorithm>

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

ListNode* gcd(ListNode* first, ListNode* second) {

    int ans = __gcd(first -> data, second -> data);
    return new ListNode(ans);
}

ListNode* insertGreatestCommonDivisors(ListNode* head) {

    ListNode* prev = head;
    ListNode* curr = head -> next;

    while(curr != NULL) {

        ListNode* inser = gcd(prev, curr);
        prev -> next = inser;
        inser -> next = curr;

        curr = curr -> next;
        prev = prev -> next;
    }

    return head;
}