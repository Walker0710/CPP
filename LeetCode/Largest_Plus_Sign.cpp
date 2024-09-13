#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>

using namespace std;

int orderOfLargestPlusSign(int n, vector<vector<int>> &mines)
{

    vector<vector<int>> dp(n, vector<int>(n, 1));

    for (int i = 0; i < mines.size(); i++)
    {
        dp[mines[i][0]][mines[i][1]] = 0;
    }

    int order = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (dp[i][j] == 0)
                continue;

            int left = 0;
            int k = j;
            while (k >= 0 && dp[i][k] == 1)
            {
                left++;
                k--;
            }

            int right = 0;
            k = j;
            while (k < n && dp[i][k] == 1)
            {
                right++;
                k++;
            }

            int top = 0;
            k = i;
            while (k >= 0 && dp[k][j] == 1)
            {
                top++;
                k--;
            }

            int down = 0;
            k = i;
            while (k < n && dp[k][j] == 1)
            {
                down++;
                k++;
            }

            order = max(order, min(right, min(left, min(top, down))));
        }
    }

    return order;
}

//dp
int orderOfLargestPlusSign(int n, vector<vector<int>> &mines)
{
    vector<vector<int>> dp(n, vector<int>(n, 1));

    for (int i = 0; i < mines.size(); i++)
    {
        dp[mines[i][0]][mines[i][1]] = 0;
    }

    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (dp[i][j] == 0)
            continue;
        
            int down = 0;
            int k = i;
            while (k < n && dp[k][j] == 1)
            {
                down++;
                k++;
            }

            int right = 0;
            k = j;
            while (k < n && dp[i][k] == 1)
            {
                right++;
                k++;
            }

            dp[i][j] = min(right, min(down, min(dp[i-1][j]+1, dp[i][j-1]+1)));
            ans = max(ans, dp[i][j]);
        }
    }

    if (ans == 0) {

        for(int i = 0; i<n; i++) {
           if(dp[0][i] == 1 || dp[i][0] == 1)
           ans = 1; 
        }
    }
    
    return ans;
}