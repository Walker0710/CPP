#include <bits/stdc++.h>

using namespace std;

// << ,

int minimumPushes(string word)
{
    vector<int> freq(26, 0);

    for (char c : word)
    {
        freq[c - 'a']++;
    }

    sort(freq.rbegin(), freq.rend());

    int sum = 0;
 
    for (int i = 0; i < 26; i++)
    {
        sum += freq[i] * ((i + 8) / 8);
    }

    return sum;
}