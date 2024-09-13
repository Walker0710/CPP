#include<iostream>
#include<stack>

using namespace std;

//1st approch
class MinStack {
public:

    stack<int>s;
    stack<int> minwli;
    int mini = INT32_MAX;

    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        mini = min(val, mini);
        minwli.push(mini);
    }
    
    void pop() {

        s.pop();
        minwli.pop();
    }
    
    int top() {

        return s.top();
    }
    
    int getMin() {

        return minwli.top();
    }
};

//2nd approch
class MinStack {
public:

    stack<int>s;
    stack<int> minwli;
    int mini = INT32_MAX;

    MinStack() {
        
    }
    
    void push(int val) {

        if(s.empty()) {

            s.push(val);
            mini = min(val, mini);
            minwli.push(mini);
        }

        else {

            s.push(val);
            mini = min(val, minwli.top());
            minwli.push(mini);
        }
    }
    
    void pop() {

        s.pop();
        minwli.pop();

        if(s.empty()) {

            mini = INT32_MAX;
        }
    }
    
    int top() {

        return s.top();
    }
    
    int getMin() {

        return minwli.top();
    }
};