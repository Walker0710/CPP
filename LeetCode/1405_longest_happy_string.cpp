#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

// first attempt
string longestDiverseString(int a, int b, int c)
{
    priority_queue<pair<int, char>> maxHeap;

    if (a != 0)
        maxHeap.push({a, 'a'});
    if (b != 0)
        maxHeap.push({b, 'b'});
    if (c != 0)
        maxHeap.push({c, 'c'});

    string ans;
    pair<int, char> prev = {-1, '#'};

    while (!maxHeap.empty())
    {
        auto curr = maxHeap.top();
        maxHeap.pop();

        if (curr.first >= 2)
        {
            ans = ans + curr.second + curr.second;
            curr.first = curr.first - 2;
        }

        else if (curr.first == 1)
        {
            ans = ans + curr.second;
            curr.first = curr.first - 1;
        }

        if (prev.first > 0)
            maxHeap.push(prev);

        prev = curr;

        if (maxHeap.empty() && curr.second > 0)
        {
            break;
        }
    }
    return ans;
}

string longestDiverseString(int a, int b, int c)
{
    priority_queue<pair<int, char>> maxHeap;

    if (a != 0)
        maxHeap.push({a, 'a'});
    if (b != 0)
        maxHeap.push({b, 'b'});
    if (c != 0)
        maxHeap.push({c, 'c'});

    string ans = "";
    while (maxHeap.size() > 1)
    {
        pair<int, char> fir = maxHeap.top();
        maxHeap.pop();

        pair<int, char> sec = maxHeap.top();
        maxHeap.pop();

        ans = ans + fir.second;
        fir.first--;
        if (fir.first > 0)
        {
            ans = ans + fir.second;
            fir.first--;
        }

        ans = ans + sec.second;
        sec.first--;
        if ((sec.first > 0) && (fir.first - sec.first < 2)) //most imp condition
        {
            ans = ans + sec.second;
            sec.first--;
        }

        if (fir.first > 0)
        {
            maxHeap.push(fir);
        }

        if (sec.first > 0)
        {
            maxHeap.push(sec);
        }
    }
    if (!maxHeap.empty())
    {
        pair<int, char> fir = maxHeap.top();
        maxHeap.pop();

        ans = ans + fir.second;
        fir.first--;
        if (fir.first > 0)
        {
            ans = ans + fir.second;
            fir.first--;
        }
    }

    return ans;
}
