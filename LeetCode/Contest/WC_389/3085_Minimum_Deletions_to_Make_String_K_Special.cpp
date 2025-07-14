#include <bits/stdc++.h>

using namespace std;

// << ,

int minimumDeletions(string word, int k)
{
    unordered_map<char, int> freMp;
    for (char c : word)
    {
        freMp[c]++;
    }

    vector<int> freq;
    for (auto &pair : freMp)
    {
        freq.push_back(pair.second);
    }
    sort(freq.begin(), freq.end());

    int minDele = INT_MAX;
    int n = freq.size();

    for (int i = 0; i < n; ++i)
    {
        int base = freq[i];
        int totalDele = 0;

        for (int j = 0; j < i; ++j)
        {
            totalDele += freq[j];
        }

        for (int j = i; j < n; ++j)
        {
            if (freq[j] > base + k)
            {
                totalDele += freq[j] - (base + k);
            }
        }

        if (totalDele < minDele)
        {
            minDele = totalDele;
        }
    }

    return minDele;
}