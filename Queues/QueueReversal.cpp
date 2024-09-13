#include<iostream>
#include<queue>
#include<stack>

using namespace std;

queue<int> rev(queue<int> q) {

    stack<int> copy;

    while (!q.empty())
    {
        int element = q.front();
        q.pop();

        copy.push(element); 
    }

    while (!copy.empty())
    {
        int element = copy.top();
        copy.pop();

        q.push(element);
    }

    return q;
}


//2nd 

class Solution
{
    private:
    
    void reve(queue<int> &q) {

    //base case
    if(q.empty()) {

        return ;
    }

    int curr = q.front();
    q.pop();

    reve(q);

    q.push(curr);
}

    public:


queue<int> rev(queue<int> q) {

    reve(q);

    return q;
}
};


