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

ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

    ListNode* leftPrev = NULL;;
    ListNode* left = list1;
    ListNode* right = list1;

    while (a)
    {
        leftPrev = left;
        left = left -> next;
        a--;
    }

    while (b) 
    {
        right = right -> next;
        b--;
    }

    right = right -> next;

    ListNode* list2Tail = list2;

    while(list2Tail -> next != NULL) {

        list2Tail = list2Tail -> next;
    }

    leftPrev -> next = list2;
    list2Tail -> next = right;

    return list1;
}