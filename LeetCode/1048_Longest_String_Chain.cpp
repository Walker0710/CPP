#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isValid(vector<string> &words, int index, int prev)
{
    string curr = words[index];
    string prevW = words[prev];

    if (curr.length() - 1 != prevW.length())
        return false;

    int i = 0;
    int j = 0;
    int count = 0;

    while (i < curr.length() && j < prevW.length())
    {
        if (prevW[j] == curr[i])
        {
            j++;
            count++;
        }

        i++;
    }

    return count == prevW.length();
}

int solve(vector<string> &words, int index, int prev)
{

    if (index == words.size())
        return 0;

    int inc = 0;
    int exc = 0;
    int ans = 0;

    if (prev == -1 || isValid(words, index, prev))
    {
        inc = 1 + solve(words, index + 1, index);
    }

    exc = solve(words, index + 1, prev);

    ans = max(inc, exc);

    return ans;
}

static bool comparator(string &s1, string &s2)
{
    return s1.length() < s2.length();
}

int longestStrChain(vector<string> &words)
{
    sort(words.begin(), words.end(), comparator);
    return solve(words, 0, -1);
}

// rec + mem

int n;
bool check(string &prev, string &curr)
{
    int M = prev.length();
    int N = curr.length();

    if (M >= N || N - M != 1)
        return false;

    int i = 0, j = 0;
    while (i < M && j < N)
    {
        if (prev[i] == curr[j])
        {
            i++;
        }
        j++;
    }
    return i == M;
}

int solve(int i, int prev, vector<string> &words, vector<vector<int>> &dp)
{
    if (i == n)
        return 0;

    if (dp[i][prev + 1] != -1)
        return dp[i][prev + 1];

    int take = 0;
    int notake = 0;

    if (prev == -1 || check(words[prev], words[i]) == true)
    {
        take = 1 + solve(i + 1, i, words, dp);
    }
    notake = solve(i + 1, prev, words, dp);

    return dp[i][prev + 1] = max(take, notake);
}

static bool comparator(string &s1, string &s2)
{
    return s1.length() < s2.length();
}

int longestStrChain(vector<string> &words)
{
    n = words.size();
    vector<vector<int>> dp(n + 1, vector<int>(1001, -1));
    sort(words.begin(), words.end(), comparator);
    return solve(0, -1, words, dp);
}

// tabulation
static bool comparator(string &s1, string &s2)
{
    return s1.length() < s2.length();
}

int longestStrChain(vector<string> &words)
{
    int n = words.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    sort(words.begin(), words.end(), comparator);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev = n - 2; prev >= 0; prev--)
        {
            int take = 0;
            int notake = 0;

            if (prev == -1 || check(words[prev], words[i]) == true)
            {
                take = 1 + dp[i + 1][i];
            }
            notake = dp[i + 1][prev];
            dp[i][prev] = max(take, notake);
        }
    }
    return dp[0][0];
}

//leetcode
int longestStrChain(vector<string> &words)
{
    int ans = 0;
    unordered_map<string, int> dp;

    sort(words.begin(), words.end(), sortByLength);
    for (string word : words)
    {
        for (int i = 0; i < word.length(); i++)
        {
            string predecessor = word.substr(0, i) + word.substr(i + 1);
            dp[word] = max(dp[word], dp[predecessor] + 1);
        }
        ans = max(ans, dp[word]);
    }
    return ans;
}
static bool sortByLength(string &s1, string &s2)
{
    return s1.length() < s2.length();
}