#include <bits/stdc++.h>

using namespace std;

// << ,

int minFlips(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int answer = 0;

    for (int i = 0; i < m / 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            int first = grid[i][j];
            int second = grid[i][n - j - 1];
            int third = grid[m - i - 1][j];
            int fourth = grid[m - i - 1][n - j - 1];

            int zerosCount = (first == 0) + (second == 0) + (third == 0) + (fourth == 0);
            int onesCount = (first == 1) + (second == 1) + (third == 1) + (fourth == 1);

            answer += min(zerosCount, onesCount);
        }
    }

    int unSimilarPairs = 0;
    int similarPairs = 0;

    if (m % 2 != 0)
    {
        for (int j = 0; j < n / 2; j++)
        {
            if (grid[m / 2][j] != grid[m / 2][n - j - 1])
            {
                unSimilarPairs += 1;
                answer += 1;
            }

            else
            {
                if (grid[m / 2][j] == 1)
                    similarPairs += 1;
            }
        }
    }

    if (n % 2 != 0)
    {
        for (int i = 0; i < m / 2; i++)
        {
            if (grid[i][n / 2] != grid[m - i - 1][n / 2])
            {
                unSimilarPairs += 1;
                answer += 1;
            }

            else
            {
                if (grid[i][n / 2] == 1)
                    similarPairs += 1;
            }
        }
    }

    if (m % 2 != 0 and n % 2 != 0)
    {
        answer += (grid[m / 2][n / 2] == 1);
    }

    if (similarPairs % 2 != 0)
    {
        if (unSimilarPairs == 0)
        answer += 2;
    }

    return answer;
}