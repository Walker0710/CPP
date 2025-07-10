#include <bits/stdc++.h>

using namespace std;

// << ,

int findWinningPlayer(vector<int> &skills, int k)
{
    int n = skills.size();

    if (k >= n)
    {
        int mixi = 0;
        int ind = 0;

        for (int i = 0; i < n; i++)
        {
            if (skills[i] > mixi)
            {
                mixi = skills[i];
                ind = i;
            }
        }

        return ind;
    }

    deque<int> q(skills.begin(), skills.end());
    int current = q.front();
    q.pop_front();
    int wins = 0;

    while (wins < k)
    {
        int opponent = q.front();
        q.pop_front();

        if (current > opponent)
        {
            wins++;
            q.push_back(opponent);
        }
        else
        {
            q.push_back(current);
            current = opponent;
            wins = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (skills[i] == current)
            return i;
    }

    return 0;
}
