#include <bits/stdc++.h>

using namespace std;

// << ,

int minimumOperationsToMakeKPeriodic(string word, int k)
{
    int n = word.length();

    string st = word.substr(n - k, k);
    int ans = 0;

    for (int i = 0; i + k <= n; i = i + k)
    {
        if (word.substr(i, k) != st)
        {
            ans++;
        }
    }

    return ans;
}



int minimumOperationsToMakeKPeriodic(string word, int k)
{
    unordered_map<string, int> freq;
    int n = word.length();

    for (int i = 0; i < n; i += k)
    {
        string sub = word.substr(i, k);
        freq[sub]++;
    }

    int maxFreq = 0;
    for (auto &[s, count] : freq)
    {
        maxFreq = max(maxFreq, count);
    }

    int totalBlocks = n / k;
    return totalBlocks - maxFreq;
}