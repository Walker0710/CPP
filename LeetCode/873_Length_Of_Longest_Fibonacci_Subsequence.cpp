#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// only rec
int solve(int index, int sum, vector<int> &arr)
{

    if (index >= arr.size())
        return 0;

    int ans = 0;

    for (int i = index + 1; i < arr.size(); i++)
    {

        if (arr[i] == sum)
        {
            ans = max(ans, 1 + solve(i, arr[i] + arr[index], arr));
        }
    }

    return ans;
}

int lenLongestFibSubseq(vector<int> &arr)
{

    int ans = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {

            ans = max(ans, 2 + solve(j, arr[i] + arr[j], arr));
        }
    }

    if (ans <= 2)
        return 0;

    return ans;
}

// rec + mem
int solveMem(int index, int sum, vector<int> &arr, vector<vector<int>> &dp)
{

    if (index >= arr.size())
        return 0;

    if (dp[index][sum] != -1)
        return dp[index][sum];

    int ans = 0;

    for (int i = index + 1; i < arr.size(); i++)
    {

        if (arr[i] == sum)
        {
            ans = max(ans, 1 + solveMem(i, arr[i] + arr[index], arr, dp));
        }
    }

    return dp[index][sum] = ans;
}

int lenLongestFibSubseq(vector<int> &arr)
{

    int ans = 0;
    vector<vector<int>> dp(arr.size() + 1, vector<int>(arr[arr.size() - 1] + arr[0] + 1, -1));

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {

            ans = max(ans, 2 + solveMem(j, arr[i] + arr[j], arr, dp));
        }
    }

    if (ans <= 2)
        return 0;

    return ans;
}

// using map
int solveMem2(int index, int sum, vector<int> &arr, unordered_map<int, int> dp[])
{

    if (index >= arr.size())
        return 0;

    if (dp[index].count(sum))
        return dp[index][sum];

    int ans = 0;

    for (int i = index + 1; i < arr.size(); i++)
    {

        if (arr[i] == sum)
        {
            ans = max(ans, 1 + solveMem2(i, arr[i] + arr[index], arr, dp));
        }
    }

    return dp[index][sum] = ans;
}

int lenLongestFibSubseq(vector<int> &arr)
{

    int ans = 0;
    unordered_map<int, int> dp[arr.size() + 1];

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {

            ans = max(ans, 2 + solveMem2(j, arr[i] + arr[j], arr, dp));
        }
    }

    if (ans <= 2)
        return 0;

    return ans;
}

// using binary search
int solv(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (j >= arr.size() || i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int x = 0;
    int l = j + 1, r = arr.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == arr[j] + arr[i])
        {
            x = 1 + solv(j, mid, arr, dp);
            break;
        }
        else if (arr[mid] > arr[j] + arr[i])
        {
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return dp[i][j] = x;
}

int lenLongestFibSubseq(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int ans = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < arr.size(); i++)
    {
        m[arr[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (m.find(arr[i] + arr[j]) != m.end())
                ans = max(ans, 2 + solv(i, j, arr, dp));
        }
    }
    return ans >= 3 ? ans : 0;
}

int lenLongestFibSubseq(vector<int> &A)
{
    unordered_set<int> s(A.begin(), A.end());
    int res = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        for (int j = i + 1; j < A.size(); ++j)
        {
            int a = A[i], b = A[j], l = 2;
            while (s.count(a + b))
                b = a + b, a = b - a, l++;
            res = max(res, l);
        }
    }
    return res > 2 ? res : 0;
}