#include <bits/stdc++.h>

using namespace std;

// << ,

long long validSubstringCount(string word1, string word2)
{
    vector<int> freq(26, 0);
    int cnt = 0;
 
    for (char ch : word2)
    {
        if (freq[ch - 'a'] == 0)
        {
            cnt++;
        }
        freq[ch - 'a']++;
    }
 
    long long j = 0, ans = 0;
 
    for (long long i = 0; i < word1.size(); i++)
    {
        if (--freq[word1[i] - 'a'] == 0)
        {
            cnt--;
        }
 
        while (cnt == 0)
        {
            ans += (word1.size() - i);
            if (++freq[word1[j] - 'a'] == 1)
            {
                cnt++;
            }
            j++;
        }
    }
 
    return ans;
}