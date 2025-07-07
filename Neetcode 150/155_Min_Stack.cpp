#include <bits/stdc++.h>

using namespace std;

// << ,

class MinStack
{
public:
    stack<int> s;
    stack<int> minwli;
    int mini = INT32_MAX;

    MinStack()
    {
    }

    void push(int val)
    {
        if (s.empty())
        {
            s.push(val);
            mini = min(val, mini);
            minwli.push(mini);
        }

        else
        {
            s.push(val);
            mini = min(val, minwli.top());
            minwli.push(mini);
        }
    }

    void pop()
    {
        s.pop();
        minwli.pop();

        if (s.empty())
        {
            mini = INT32_MAX;
        }
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return minwli.top();
    }
};


class SpecialStack
{
    stack<int> s;
    int mini = INT32_MAX;

public:
    void push(int data)
    {
        if (s.empty())
        {
            s.push(data);
            mini = data;
        }

        else
        {
            if (data < mini)
            {
                s.push(2 * data - mini);
                mini = data;
            }

            else
            {
                s.push(data);
            }
        }
    }

    int pop()
    {
        if (s.empty())
        {
            return -1;
        }

        int curr = s.top();
        s.pop();

        if (curr > mini)
        {
            return curr;
        }

        else
        {
            int prevMin = mini;
            int val = 2 * mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top()
    {
        if (s.empty())
        {
            return -1;
        }

        int curr = s.top();

        if (curr < mini)
        {
            return mini;
        }

        else
        {
            return curr;
        }
    }

    bool isEmpty()
    {
        return s.empty();
    }

    int getMin()
    {
        if (s.empty())
        {
            return -1;
        }

        return mini;
    }
};