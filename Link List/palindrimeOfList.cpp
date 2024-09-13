#include<iostream>
#include<vector>

using namespace std;

class Node {

    public:
    int data;
    Node* next;

    //constructor
    Node(int d) {

        this -> data = d;
        this -> next = NULL;
    }
};

//first approch

bool checkPalindrome(vector<int> &arr) {

    int n = arr.size();
    int s = 0;
    int e = n-1;

    while(s<=e) {

        if(arr[s] != arr[e]) {

            return 0;
        }

        s++;
        e--;
    }

    return 1;
}

bool isPalindrome(Node* head) {

    vector<int> arr;

    Node* temp = head;

    while(temp != NULL) {

        arr.push_back(temp -> data);
        temp = temp -> next;
    }

    return checkPalindrome(arr);
}

//2nd approch

Node* getMid(Node* head) {

    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL && fast -> next != NULL) {

        fast = fast -> next -> next;
        slow = slow -> next;
    }

    return slow;
}

Node* reverse(Node* head) {

    Node* curr = head;
    Node* prev = NULL;
    Node* Next = NULL;

    while(curr != NULL) {

        Next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = Next; 
    }

    return prev;
}

bool ispalindrome2(Node* head) {

    if(head -> next == NULL) {

        return true;
    }

    Node* middle = getMid(head);

    //reversing the list after the middle
    Node* temp = middle -> next;
    middle -> next = reverse(temp);

    Node* head1 = head;
    Node* head2 = middle -> next;

    while(head2 != NULL) {

        if(head1 -> data != head2 -> data) {

            return false;
        }

        else {

            head1 = head1 -> next;
            head2 = head2 -> next;
        }
    }

    // ye part optional h bas apan list ko jasi thi wase he bna de rhe h wapas
    temp = middle -> next;
    middle -> next = reverse(temp);

    return true;
}