#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

queue<int> modifyQueue(queue<int> q, int k) {

    stack<int> s;
    int n = q.size();

    //pop first k element from q to stack
    for(int i = 0; i<k; i++) {

        int ele = q.front();
        q.pop();

        s.push(ele);
    }

    //fetch from stack and push it into q
    for(int i = 0; i<k; i++) {

        int el = s.top();
        s.pop();

        q.push(el);
    }

    //fecth first (n-k) element from q and push back
    int rem = n-k;

    for(int i = 0; i< rem; i++) {

        int e = q.front();
        q.pop();

        q.push(e);
    }

    return q;
}

