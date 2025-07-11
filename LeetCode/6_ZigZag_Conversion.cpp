#include <bits/stdc++.h>

using namespace std;

// << ,

string convert(string s, int numRows)
{
    int n = s.size();

    if (numRows == 1)
        return s;

    int cnt = n;
    int cols = 0;
    bool isSt = true;

    while (cnt > 0)
    {
        if (isSt)
        {
            cols++;
            cnt -= numRows;
            isSt = false;
        }
        else
        {
            cols = cols + min(cnt, numRows - 2);
            cnt -= (numRows - 2);
            isSt = true;
        }
    }

    vector<vector<char>> grid(numRows, vector<char>(cols, ' '));

    isSt = true;
    cnt = 0;
    int j = 0;

    while (j < cols)
    {
        if (isSt)
        {
            for (int i = 0; i < numRows && cnt < n; i++)
            {
                grid[i][j] = s[cnt++];
            }
            isSt = false;
            j++;
        }
        else
        {
            for (int i = numRows - 2; i > 0 && cnt < n; i--)
            {
                grid[i][j] = s[cnt++];
                j++;
            }
            isSt = true;
        }
    }

    string ans = "";
    
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] != ' ')
            ans += grid[i][j];
        }
    }

    return ans;
}