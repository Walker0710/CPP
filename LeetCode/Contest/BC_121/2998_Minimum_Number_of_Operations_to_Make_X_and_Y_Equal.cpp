#include <bits/stdc++.h>

using namespace std;

// << ,

int minimumOperationsToMakeEqual(int x, int y)
{
    queue<int> q;
    unordered_set<int> visited;

    q.push(x);
    visited.insert(x);
    int cnt = 0;

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            int top = q.front();
            q.pop();

            if (top == y)
                return cnt;

            if (top % 11 == 0 && visited.count(top / 11) == 0)
            {
                q.push(top / 11);
                visited.insert(top / 11);
            }

            if (top % 5 == 0 && visited.count(top / 5) == 0)
            {
                q.push(top / 5);
                visited.insert(top / 5);
            }

            if (visited.count(top + 1) == 0)
            {
                q.push(top + 1);
                visited.insert(top + 1);
            }

            if (visited.count(top - 1) == 0 && top > 1)
            {
                q.push(top - 1);
                visited.insert(top - 1);
            }
        }
        cnt++;
    }

    return -1;
}