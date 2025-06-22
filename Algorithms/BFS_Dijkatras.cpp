#include <bits/stdc++.h>

using namespace std;

// << ,

// Que 1

int minTimeToReach(vector<vector<int>> &moveTime)
{
    int n = moveTime.size();
    int m = moveTime[0].size();

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minH;
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX)); // basically visi arr

    minH.push({0, 0, 0});
    moveTime[0][0] = 0;

    vector<vector<int>> dirc = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!minH.empty())
    {
        vector<int> yoo = minH.top();
        minH.pop();

        int t = yoo[0];
        int r = yoo[1];
        int c = yoo[2];

        if (t >= dp[r][c])
            continue;

        if (r == n - 1 && c == m - 1)
            return t;

        dp[r][c] = t;

        for (auto &d : dirc)
        {
            int row = r + d[0];
            int col = c + d[1];

            if (row >= 0 && row < n && col >= 0 && col < m && dp[row][col] == INT_MAX)
            {
                int exTime = max(moveTime[row][col], t) + 1;
                minH.push({exTime, row, col});
            }
        }
    }
    return -1;
}



// Que 2

vector<int> isPrime;

void generatePrimes()
{
    if (!isPrime.empty())
        return;

    isPrime.resize(1e5 + 1, 1);
    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i <= 1e5; i++)
    {
        if (isPrime[i])
        {
            for (int j = 2 * i; j <= 1e5; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
}

int minOperations(int n, int m)
{
    generatePrimes();

    if (isPrime[n] || isPrime[m])
        return -1;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    unordered_set<int> visited;

    q.push({n, n});

    while (!q.empty())
    {
        auto [steps, curr] = q.top();
        q.pop();

        if (visited.count(curr))
            continue;

        visited.insert(curr);

        if (curr == m)
            return steps;

        string s = to_string(curr);

        for (int i = 0; i < s.length(); i++)
        {
            char original = s[i];

            if (s[i] < '9')
            {
                s[i]++;
                int next = stoi(s);

                if (!isPrime[next] && !visited.count(next))
                {
                    q.push({steps + next, next});
                }
                s[i] = original;
            }

            if (s[i] > '0' && !(i == 0 && s[i] == '1'))
            {
                s[i]--;
                int next = stoi(s);

                if (!isPrime[next] && !visited.count(next))
                {
                    q.push({steps + next, next});
                }
                s[i] = original;
            }
        }
    }
    return -1;
}