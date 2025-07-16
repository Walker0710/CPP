#include <bits/stdc++.h>

using namespace std;

// << ,

int mostFrequentPrime(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    map<int, int> mp;

    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    vector<int> prime(1e6, 1);
    prime[0] = prime[1] = 0;

    for (int i = 2; i * i < 1e6; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j < 1e6; j += i)
            {
                prime[j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (auto [dx, dy] : dir)
            {
                int x = i;
                int y = j;

                int num = 0;

                while (x < n && x >= 0 && y < m && y >= 0)
                {
                    num = num * 10 + mat[x][y];

                    if (num > 10 && prime[num])
                    {
                        mp[num]++;
                    }

                    x += dx;
                    y += dy;
                }
            }
        }
    }

    int ans = -1;
    int freq = -1;

    for (auto [val, count] : mp)
    {
        if (count > freq || (count == freq && val > ans))
        {
            freq = count;
            ans = val;
        }
    }

    return ans;
}