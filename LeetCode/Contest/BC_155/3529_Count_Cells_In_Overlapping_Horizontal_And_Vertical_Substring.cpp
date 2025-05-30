#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> lps;
void countLPS(string &str)
{
    int n = str.size();
    for (int i = 1; i < n; ++i)
    {
        int len = lps[i - 1];
        while (len > 0 && str[len] != str[i])
        {
            len = lps[len - 1];
        }
        if (str[len] == str[i])
            ++len;
        lps[i] = len;
    }
}

int countCells(vector<vector<char>> &grid, string pattern)
{
    int m = grid.size();
    int n = grid[0].size();

    string hor(m * n, 0), ver(m * n, 0);
    int count = 0;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            hor[count++] += grid[i][j];
        }
    }

    count = 0;

    for (int j = 0; j < n; ++j)
    {
        for (int i = 0; i < m; ++i)
        {
            ver[count++] += grid[i][j];
        }
    }

    int pLen = pattern.size();
    lps.resize(pLen, 0);
    countLPS(pattern);

    vector<int> horKMP(m * n, 0);
    int done = -1;

    for (int i = 0; i < m * n; ++i)
    {
        int len = i == 0 ? 0 : horKMP[i - 1];
        if (len == pLen)
            len = lps.back();

        while (len > 0 && pattern[len] != hor[i])
        {
            len = lps[len - 1];
        }

        if (pattern[len] == hor[i])
            ++len;

        horKMP[i] = len;

        if (len == pLen)
        {
            int start = max(done + 1, i - pLen + 1);

            for (; start <= i; ++start)
            {
                int x = start % n;
                int y = start / n;
                grid[y][x] = 1;
            }

            done = i;
        }
    }

    int result = 0;
    done = -1;
    vector<int> verKMP(m * n, 0);

    for (int i = 0; i < m * n; ++i)
    {
        int len = i == 0 ? 0 : verKMP[i - 1];
        if (len == pLen)
            len = lps.back();

        while (len > 0 && pattern[len] != ver[i])
        {
            len = lps[len - 1];
        }

        if (pattern[len] == ver[i])
            ++len;

        verKMP[i] = len;

        if (len == pLen)
        {
            int start = max(done + 1, i - pLen + 1);

            for (; start <= i; ++start)
            {
                int x = start / m;
                int y = start % m;
                if (grid[y][x] == 1)
                    ++result;
            }
            done = i;
        }
    }
    return result;
}