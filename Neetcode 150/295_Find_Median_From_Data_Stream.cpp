#include <bits/stdc++.h>

using namespace std;

// << ,

class MedianFinder
{
public:
    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<int>> mn;

    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (mx.empty() || nums <= mx.top())
        {
            mx.push(num);
        }

        else
        {
            mn.push(num);
        }

        int x = mx.size();
        int n = mn.size();

        if (x - n > 1 || n - x > 1)
        {
            if (mx.size() > mn.size())
            {
                mn.push(mx.top());
                mx.pop();
            }

            else
            {
                mx.push(mn.top());
                mn.pop();
            }
        }
    }

    double findMedian()
    {
        if (mx.size() == mn.size())
        {
            // we have an even case
            double sum = mx.top() + mn.top();
            return sum / 2.0;
        }
        else
        {
            // the odd case
            if (mx.size() > mn.size())
            {
                return mx.top();
            }
            else
                return mn.top();
        }
    }
};