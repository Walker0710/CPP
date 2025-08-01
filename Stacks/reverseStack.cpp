#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int> &s, int element) {

    if(s.empty()) {

        s.push(element);
        return;
    }

    int num = s.top();
    s.pop();

    insertAtBottom(s, element);

    s.push(num);
}

void reverseStack(stack<int> &stack) {

    //base case 
    if(stack.empty()) {

        return ;
    }

    int num = stack.top();

    reverseStack(stack);

    insertAtBottom(stack, num);
}